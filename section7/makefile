CC=g++
IDIR=./include #include path
CFLAGS=-I$(IDIR)-g -Wall # flag to include
_DEPS=Complex.h # list of .h file
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS)) # concate include path with the .h file names 
ODIR=obj
OBJ=main7-2.o Complex.o # .o files
BINARIES=main7-2

all: main7-2

#  the -o $@ says to put the output of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
#  special macros $@ and $^, which are the left and right sides of the :, respectively, to make the overall compilation rule more general
main7-2: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

# The .PHONY rule keeps make from doing something with a file named clean.
.PHONY: clean

clean:
	rm *.o $(BINARIES)