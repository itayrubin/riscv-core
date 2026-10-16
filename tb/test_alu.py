import random
import cocotb
from cocotb.triggers import Timer

MASK = 0xFFFFFFFF

def to_signed(v):
	return v - (1 << 32) if v & (1 << 31) else v
def model(a, b, op):
	if op == 0: return (a + b) & MASK
	if op == 1: return (a - b) & MASK
	if op == 2: return a & b
	if op == 3: return a | b
	if op == 4: return a ^ b
	if op == 5: return ( a << (b & 31)) & MASK
	if op == 6: return a >> (b & 31)
	if op == 7: return 1 if to_signed(a) < to_signed(b) else 0
	return 0
async def check(dut, a, b, op):
	dut.a.value = a
	dut.b.value = b
	dut.op.value = op
	await Timer(1, unit = "ns")
	got = int(dut.result.value)
	want = model(a, b, op)
	assert got == want, f"op={op} a={a:#x} b={b:#x} got {got:#x}, want {want:#x}"
@cocotb.test()
async def test_edge_cases(dut):
	values = [0, 1, 2, 0xFFFFFFFF, 0x80000000, 0X7FFFFFFF]
	len = 8
	for op in range (len):
		for a in values:
			for b in values:
				await check(dut,a,b,op)
@cocotb.test()
async def test_random(dut):
	len = 500
	bits = 32
	byte = 8
	for _ in range(len):
		await check(dut, random.getrandbits(bits), random.getrandbits(bits), random.randrange(byte))
