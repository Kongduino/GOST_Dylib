.POSIX:
TARGET = kuznechik
CC = gcc
CFLAGS = -Ofast -g

# The list of object files.
OBJS =  gost_3412_2015_calc.o	main.o

# the list of files to clean
TOCLEAN = kuznechik.dylib $(OBJS)

RM ?= rm -f

all: $(TARGET)
clean:
	$(RM) $(TOCLEAN)

kuznechik: $(OBJS)
	$(CC) $(CFLAGS) *.c
	$(CC) -dynamiclib gost_3412_2015_calc.o -o $(TARGET).dylib
	$(CC) *.o -o kuznechik_test
	rm *.o *.out
	./kuznechik_test
	cd Python ; ./Test.py

install:
	cp $(TARGET).dylib /usr/local/lib/