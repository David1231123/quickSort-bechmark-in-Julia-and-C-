# Makefile für Julia
SHELL := /bin/bash
	
time_quickSort_optim: quickSort/quickSort_optim.jl
	/usr/bin/time -f "%e" julia $< 2>> ../MeasuredTime/time_quickSort.csv \
	