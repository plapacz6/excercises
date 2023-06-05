all: Tests_IList2d_01

CFLAGS= g3 -std=c11

IList2d.o: IList2d.c IList2d.h
	$(CC) $(FLAGS) $< -c

Tests_IList2d_01: Tests_IList2d_01.o IList2d.o
	$(CC) $(FLAGS) $^ -o $@

Tests_IList2d_01.o: Tests_IList2d_01.c IList2d.h
	$(CC) $(FLAGS) $< -c

.PHONY: clean

clean:
	-rm IList2d Tests_IList2d_01 *.o
