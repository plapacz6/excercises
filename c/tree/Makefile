all: atree__with_array
CFLAGS=	-g3 -std=c11
btree__with_array : tree__with_array_1.c
	$(CC) $(CFLAGS) $< -o $@

atree__with_array: tree__with_array.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm btree__with_array atree__with_array a.out
