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

TARGETS=bin/CS460_Fork bin/dup2_example
all: bin ${TARGETS}

bin:
	mkdir -p bin

bin/CS460_Fork: bin/CS460_Fork.o
	${CC} ${CFLAGS} -o bin/CS460_Fork bin/CS460_Fork.o
        
bin/CS460_Fork.o: src/CS460_Fork.c
	${CC} ${CFLAGS} -c -o bin/CS460_Fork.o src/CS460_Fork.c 

bin/dup2_example: bin/dup2_example.o
	${CC} ${CFLAGS} -o bin/dup2_example bin/dup2_example.o
        
bin/dup2_example.o: src/dup2_example.c
	${CC} ${CFLAGS} -c -o bin/dup2_example.o src/dup2_example.c 

clean:
	rm -f bin/*.o ${TARGETS}

printMain:
	enscript -C -T 2 -p - -M Letter -Ec --color -fCourier8 src/CS460_Fork.c  | ps2pdf - bin/CS460_Fork.pdf 
	enscript -C -T 2 -p - -M Letter -Ec --color -fCourier8 src/dup2_example.c  | ps2pdf - bin/dup2_example.pdf 

