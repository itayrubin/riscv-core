import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

SETTLE = 1  # ns, enough for combinational outputs to settle

async def start(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    dut.we.value = 0
    dut.rs1.value = 0
    dut.rs2.value = 0
    dut.rd.value = 0
    dut.wdata.value = 0
    await RisingEdge(dut.clk)
    await Timer(SETTLE, unit="ns")

async def write(dut, addr, value):
    dut.rd.value = addr
    dut.wdata.value = value
    dut.we.value = 1
    await RisingEdge(dut.clk)
    dut.we.value = 0
    await Timer(SETTLE, unit="ns")

async def read1(dut, addr):
    dut.rs1.value = addr
    await Timer(SETTLE, unit="ns")
    return int(dut.rdata1.value)

@cocotb.test()
async def test_write_then_read(dut):
    await start(dut)
    model = {}
    for addr in range(1, 32):
        value = random.getrandbits(32)
        model[addr] = value
        await write(dut, addr, value)
    for addr in range(1, 32):
        got = await read1(dut, addr)
        assert got == model[addr], f"x{addr}: got {got:#x}, want {model[addr]:#x}"

@cocotb.test()
async def test_x0_is_always_zero(dut):
    await start(dut)
    assert await read1(dut, 0) == 0
    await write(dut, 0, 0xDEADBEEF)
    assert await read1(dut, 0) == 0, "a write to x0 must be discarded"

@cocotb.test()
async def test_no_write_when_we_low(dut):
    await start(dut)
    await write(dut, 7, 0xAAAAAAAA)
    dut.rd.value = 7
    dut.wdata.value = 0xBBBBBBBB
    dut.we.value = 0
    await RisingEdge(dut.clk)
    await Timer(SETTLE, unit="ns")
    assert await read1(dut, 7) == 0xAAAAAAAA, "wrote while we was low"

@cocotb.test()
async def test_both_ports(dut):
    await start(dut)
    await write(dut, 3, 0x33333333)
    await write(dut, 9, 0x99999999)
    dut.rs1.value = 3
    dut.rs2.value = 9
    await Timer(SETTLE, unit="ns")
    assert int(dut.rdata1.value) == 0x33333333
    assert int(dut.rdata2.value) == 0x99999999

@cocotb.test()
async def test_read_during_write(dut):
    await start(dut)
    await write(dut, 5, 0x11111111)
    dut.rs1.value = 5
    dut.rd.value = 5
    dut.wdata.value = 0x22222222
    dut.we.value = 1
    await Timer(SETTLE, unit="ns")
    assert int(dut.rdata1.value) == 0x11111111, "should still read the old value"
    await RisingEdge(dut.clk)
    dut.we.value = 0
    await Timer(SETTLE, unit="ns")
    assert int(dut.rdata1.value) == 0x22222222, "new value should appear after the edge"