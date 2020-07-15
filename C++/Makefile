# Makefile für C++
SHELL := /bin/bash

BIN_PATH := ./bin
INC_PATH := ./include
EIG_PATH := ./include/eigen-3.3.7
BOOST_PATH := ./include/boost_1_73_0
SRC_PATH := ./src
OBJ_PATH := ./obj

CXX     := clang++ 
CFLAGS1 := -I ${INC_PATH} -I ${EIG_PATH} -pthread -O2
CFLAGS2 := -I ${INC_PATH} -I ${EIG_PATH} -I ${BOOST_PATH} -pthread -g -fwrapv -O2 -Wall

vpath %.h ${INC_PATH}
vpath %.cpp ${SRC_PATH} ${SRC_PATH}/quickSort

build: ${BIN_PATH}/quickSort_boost

# -- execute bin ---	
time_quickSort_boost: ${BIN_PATH}/quickSort_boost 
	/usr/bin/time -f "%e" $< 2>> ../MeasuredTime/time_quickSort.csv 

# --- compile and link ---

# quick sort boost
${BIN_PATH}/quickSort_boost: ${OBJ_PATH}/quickSort_boost.o ${OBJ_PATH}/dimension.o 
	$(CXX) $(CFLAGS1) $^ -o $@
	
${OBJ_PATH}/quickSort_boost.o: quickSort_boost.cpp dimension.h
	$(CXX) $(CFLAGS2) -c $< -o $@
	
# dimension
${OBJ_PATH}/dimension.o: dimension.cpp dimension.h
	$(CXX) $(CFLAGS2) -c $< -o $@
	
	
.PHONY: clean cleanObj

# delete bin and obj	
clean:	cleanObj 
	rm -rf bin
	mkdir bin

# entferne alle Objekt-Files		
cleanObj:
	rm -f ./obj/*.o



