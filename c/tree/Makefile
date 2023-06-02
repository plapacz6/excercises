all: tree__with_array

CFLAGS=	-g3 -std=c11

tree__with_array : tree__with_array_1.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm tree__with_array a.out
