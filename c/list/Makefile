all: Tests_IList_01

CFLAGS= g3 -std=c11

IList_01.o: IList_01.c IList_01.h
	$(CC) $(FLAGS) $< -c

Tests_IList_01: Tests_IList_01.o IList_01.o
	$(CC) $(FLAGS) $^ -o $@

Tests_IList_01.o: Tests_IList_01.c IList_01.h
	$(CC) $(FLAGS) $< -c

.PHONY: clean

clean:
	-rm IList_01 Tests_IList_01 *.o
