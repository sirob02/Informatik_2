CC = gcc
CFLAGS = -Wall -g
#CFLAGS = -g0 -O3

OBJS = buecher.o func/buecher_func.o func/buecher_utilitys.o
EXE = buecher

${EXE}: ${OBJS}
	${CC} -o $@ ${OBJS}

${OBJS}: lib/buecher_func.h

run: ${EXE}
	./${EXE}

clean:
	/bin/rm -f ${OBJS} core *.o ${EXE}

