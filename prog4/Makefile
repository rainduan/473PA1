# HEADERS = program.h headers.h

default: prog4

# program.o: program.c $(HEADERS)
#     gcc -c program.c -o program.o

prog4: prog4.c check.o
	gcc -g prog4.c check.o -o prog4 -lm -std=c99

check.o: check.c
	gcc -c check.c -o check.o -lm -std=c99

clean:
	-rm -f prog4
