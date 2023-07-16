all: Tests_IList

CFLAGS= g3 -std=c11

IList.o: IList.c IList.h
	$(CC) $(FLAGS) $< -c

Tests_IList: Tests_IList.o IList.o
	$(CC) $(FLAGS) $^ -o $@

Tests_IList.o: Tests_IList.c IList.h
	$(CC) $(FLAGS) $< -c

.PHONY: clean

clean:
	-rm IList Tests_IList *.o
