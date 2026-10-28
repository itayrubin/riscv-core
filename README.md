# RV32I CPU core

A 32-bit RISC-V processor written in Verilog, checked against an independent
reference model rather than against itself.

Each block is verified with [cocotb](https://www.cocotb.org/) testbenches that
compare the RTL against a model of the same spec written in Python (and, for
the full core, in C++). When they disagree, the test says which operation,
which inputs, what came out and what should have.

**Status:** ALU and register file built and verified. Decoder in progress.

---

## Why build it this way

Plenty of student CPU projects stop at "it runs a program". This one is as much
about the verification environment as the processor: a reference model, edge
cases chosen deliberately rather than randomly, and negative tests that check
the design *doesn't* do things it wasn't asked to.

That's the workflow design verification teams actually use, and it's where my
software background does real work rather than being beside the point.

---

## What's built

### ALU — `rtl/alu.v`

32-bit arithmetic and logic unit covering the eight RV32I operations: ADD, SUB,
AND, OR, XOR, SLL, SRL, SLT. Pure combinational logic, 3-bit operation select.

Verified over 788 cases:

- **288 edge cases** — all eight operations across `0`, `1`, `2`, `0xFFFFFFFF`,
  `0x80000000` and `0x7FFFFFFF`. Those last three are minus one, the most
  negative integer and the most positive — where sign and overflow bugs live.
- **500 random cases.**

Random stimulus alone wouldn't be enough here: the odds of randomly producing
`0x80000000` are 1 in 4 billion, and that's exactly the value that breaks a
signed comparison implemented without `$signed`.

### Register file — `rtl/regfile.v`

32 registers of 32 bits, with two combinational read ports and one synchronous
write port, so a single instruction can read both operands and write its result
in the same cycle. Register `x0` is hardwired to zero per the spec — reads
return zero and writes are discarded.

Five tests, each aimed at a specific failure mode:

| Test | What it would catch |
|---|---|
| `test_write_then_read` | wrong address decoding, registers aliasing, truncated data |
| `test_x0_is_always_zero` | a missing x0 guard on the read or the write path |
| `test_no_write_when_we_low` | ignoring write enable — a file that writes every cycle |
| `test_both_ports` | the two read ports miswired to the same source |
| `test_read_during_write` | unintended forwarding, or `=` used where `<=` belongs |

The last one pins down a deliberate design choice. Reading and writing the same
register in one cycle returns the **old** value, because the reads are
continuous assignments off the register array while the write only lands at the
clock edge. That's defined behaviour, not an accident — and it's what will
force explicit forwarding once the core is pipelined.

---

## Running the tests

Needs Verilator 5.036 or newer, Python 3, and cocotb.

```bash
pip install cocotb
make                 # ALU
make DUT=regfile     # register file
```

The Makefile is parameterised by `DUT`, and each block builds into its own
`sim_build` directory so artifacts never leak between them.

---

## Layout

```
rtl/        Verilog sources
  alu.v
  regfile.v
tb/         cocotb testbenches
  test_alu.py
  test_regfile.py
Makefile    parameterised by DUT
NOTES.md    design decisions and a log of every bug hit along the way
```

[`NOTES.md`](NOTES.md) is where the reasoning lives: why the shift amount is
masked to five bits, why `x0` is guarded in two places, what separates a latch
from a register, and a running account of what broke and how it was tracked
down.

---

## Next

- Instruction decoder — split a 32-bit instruction into its fields across the
  RV32I formats.
- Wire the blocks into a single-cycle core.
- A C++ reference model of the instruction set, run in lockstep against the RTL
  and compared after every instruction.
- Pipeline it, with hazard detection and forwarding.
- Synthesis through OpenLane on the sky130 PDK for area and timing numbers.

---

## Tools

Verilator · cocotb · GTKWave · Verilog · Python