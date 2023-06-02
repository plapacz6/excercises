all: IList_01

CFLAGS= g3 -std=c11

IList_01: IList_01.c IList_01.h
	$(CC) $(FLAGS) $< -o $@

.PHONY: clean

clean:
	-rm IList_01 *.o
