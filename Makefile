CC=clang
FLAGS=-Werror -pedantic
LIBS=-lSDL2
LIBS_TESTING=-Wl,-rpath,/usr/lib -lcriterion


citrics: main.c src/*.c src/events.h
		${CC} -o citrics main.c src/*.c ${FLAGS} ${LIBS}


test: tests/*.c src/*.c src/events.h
		${CC} -o tests/citrics_test_figures tests/test_figures.c src/*.c ${FLAGS} ${LIBS} ${LIBS_TESTING} && \
		./tests/citrics_test_figures && \
		rm ./tests/citrics_test_figures
