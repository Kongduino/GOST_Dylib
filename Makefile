.POSIX:
TARGET = kuznechik
CC = gcc
CFLAGS = -Ofast -g -c

# The list of object files.
OBJS =  gost_3412_2015_calc.o main.o

# the list of files to clean
TOCLEAN = kuznechik.dylib $(OBJS) *.out kuznechik_test silent

RM ?= rm -f

all: $(TARGET)
clean:
	$(RM) $(TOCLEAN)
	rm -rf a.out.dSYM

kuznechik: $(OBJS)
	$(CC) $(CFLAGS) *.c
	$(CC) -dynamiclib gost_3412_2015_calc.o -o $(TARGET).dylib
	$(CC) silent.o gost_3412_2015_calc.o -o silent
	$(CC) main.o gost_3412_2015_calc.o -o kuznechik_test
	./kuznechik_test
	time ./silent
	cd Python ; ./Test.py

install:
	cp $(TARGET).dylib /usr/local/lib/