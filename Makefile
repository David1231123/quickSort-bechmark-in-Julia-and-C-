#!/bin/bash
SHELL := /bin/bash  # choose the shell 

currDir := $(lastword $(MAKEFILE_LIST))

build:
	$(MAKE) -C C++/ $@; 
	
time_quickSort: 
	echo "quickSort" > algorithm.txt; \
	$(MAKE) -f $(currDir) createTxt; \
	number=0; while [[ $$number -le 100000000 ]] ; do \
		echo $$number > dim.txt; \
		$(MAKE) -C Julia/ $@_optim; \
		$(MAKE) -C C++/ $@_boost; \
		number=$$[$$number + 5000000];  \
	done; \
	$(MAKE) -f $(currDir) plotTime; \
		
 
createTxt:
	alg=`cat algorithm.txt`;\
	echo "Language,Algorithm,ProblemLength,Time(s)" > ./MeasuredTime/time_$$alg.csv; \
	
plotTime:
	alg=`cat algorithm.txt`;\
	echo plotting time $$alg...; \
	julia ./PyplotCode/plot_time_$$alg.jl;
	
	
# clean 	
.PHONY: clean cleanCObj cleanCSV 

clean: cleanCObj cleanCSV 

cleanCObj:
	$(MAKE) -C C++/ clean
	
cleanCSV:
	rm -f ./MeasuredTime/*.csv


	


	

