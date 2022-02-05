#############################################################################
# File name:  Makefile
# Author:     chadd
# Date:       2/20/2020
# Class:      CS 460
# Assignment: Fork/Exec Lab
# Purpose:    This is the Makefile for the CS460 Fork/Exec Lab    
#############################################################################

CC=gcc
CFLAGS=-g -Wall

.PHONY: all clean

TARGETS=bin/CS460_Fork bin/CS460_Fork_ParentChild bin/CS460_Fork_Exec bin/CS460_Fork_Pipe bin/dup2_example
all: bin ${TARGETS}

bin:
	mkdir -p bin

bin/%: bin/%.o
	gcc -o $@ -g -Wall $^

bin/%.o: src/%.c bin
	gcc -c -o $@ -g -Wall $<

clean:
	rm -f bin/*