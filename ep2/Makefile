CC = gcc
CFLAGS = -ansi -Wall -pedantic -o2

ep2: restaUm.o movimentos.o matrizes.o pilhas.o
	${CC} ${CFLAGS} -o ep2 $^

restaUm.o: restaUm.c
movimentos.o: movimentos.c
matrizes.o: matrizes.c
pilhas.o: pilhas.c

clean:
	rm *.o
	rm ep2
