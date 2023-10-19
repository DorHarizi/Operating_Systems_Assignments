CC = gcc  # Compiler to be used
CFLAGS = -Wall -Wextra -Werror -std=c11 -g  # Compiler flags: enable all warnings, treat warnings as errors, use C11 standard, and include debugging information
RM = rm -f  # Command to remove files
SHAREDLIB = -shared  # Flag to create shared library
DLIBFLAGS = -ldl  # Flag to link the dynamic libraries


all: cmp copy encode decode stshell  # Target to build all the programs

# Part A #
cmp: cmp.o  # cmp target depends on cmp.o
	$(CC) $(CFLAGS) -o $@ $^  # Compile and link cmp.o to produce executable cmp

copy: copy.o  # copy target depends on copy.o
	$(CC) $(CFLAGS) -o $@ $^  # Compile and link copy.o to produce executable copy


# Part B #
encode: encode.o libcodecA.so libcodecB.so  # encode target depends on encode.o and shared libraries
	$(CC) $(CFLAGS) -o $@ encode.o -L. -lcodecA -lcodecB $(DLIBFLAGS)  # Compile and link with shared libraries

decode: decode.o libcodecA.so libcodecB.so  # decode target depends on decode.o and shared libraries
	$(CC) $(CFLAGS) -o $@ decode.o -L. -lcodecA -lcodecB $(DLIBFLAGS)  # Compile and link with shared libraries

libcodecA.so: codecA.o  # Shared library libcodecA.so depends on codecA.o
	$(CC) $(CFLAGS) $(SHAREDLIB) -o $@ $^  # Create shared library

libcodecB.so: codecB.o  # Shared library libcodecB.so depends on codecB.o
	$(CC) $(CFLAGS) $(SHAREDLIB) -o $@ $^  # Create shared library

codecA.o: codecA.c codecA.h  # codecA.o depends on its source and header files
	$(CC) $(CFLAGS) -fPIC -c $^  # Compile codecA with Position Independent Code (PIC) flag

codecB.o: codecB.c codecB.h  # codecB.o depends on its source and header files
	$(CC) $(CFLAGS) -fPIC -c $^  # Compile codecB with Position Independent Code (PIC) flag


# Part C #
stshell: stshell.o  # stshell target depends on stshell.o
	$(CC) $(CFLAGS) -o $@ $^  # Compile and link stshell.o to produce executable stshell

stshell.o: stshell.c  # stshell.o depends on its source file
	$(CC) $(CFLAGS) -c $^  # Compile stshell.c

%.o: %.c  # Generic rule to compile .c files to produce .o files
	$(CC) $(CFLAGS) -c $^

.PHONY: all clean  # Specify that all and clean are not file names

clean:  # Target to clean the build artifacts
	$(RM) *.gch *.o *.a *.so *.dll *.dylib cmp copy encode decode stshell  # Remove all object files, libraries, and executables
