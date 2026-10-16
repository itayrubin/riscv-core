SIM ?= verilator
TOPLEVEL_LANG ?= verilog
VERILOG_SOURCES = $(PWD)/rtl/alu.v
TOPLEVEL = alu
MODULE = test_alu
export PYTHONPATH := $(PWD)/tb

include $(shell cocotb-config --makefiles)/Makefile.sim

