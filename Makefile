SIM ?= verilator
TOPLEVEL_LANG ?= verilog
DUT =? alu
VERILOG_SOURCES = $(PWD)/rtl/$(DUT).v
TOPLEVEL = $(DUT)
MODULE = test_$(DUT)
SIM_BUILD = $(PWD)/sim_build_$(DUT)
export PYTHONPATH := $(PWD)/tb

include $(shell cocotb-config --makefiles)/Makefile.sim

