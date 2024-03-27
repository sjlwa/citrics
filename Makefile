CC=clang
FLAGS=-Werror -pedantic
LIBS=-lSDL2

citrics: *.c events.h
		${CC} -o citrics *.c ${FLAGS} ${LIBS}
