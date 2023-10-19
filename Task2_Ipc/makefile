CC = gcc

all: stnc

stnc: sidefunctions.o stnc.o
	gcc -o stnc stnc.o sidefunctions.o
test: test.o sidefunctions.o
	gcc -o test test.o sidefunctions.o


clean:
	rm -f stnc test *.o *.txt