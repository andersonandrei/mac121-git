CC = gcc
CFLAGS = -ansi -Wall -pedantic -o2

ep2: tresReversao.o movimentos.o vetores.o pilhas.o bubbleSort.o
	${CC} ${CFLAGS} -o ep3 $^

tresReversao.o: tresReversao.c
movimentos.o: movimentos.c
vetores.o: vetores.c
pilhas.o: pilhas.c
bubbleSort.o: bubbleSort.c

clean:
	rm *.o
	rm ep3
