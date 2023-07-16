CFLAGS = -g3 --std=c11

find_binary_gap: find_binary_gap.c 
	$(CC) $($CFLAGS) $< -o $@

find_odd_number_in_array: find_odd_number_in_array.c
	$(CC) $($CFLAGS) $< list2direction/IList2d.o -o $@

rotate_array: rotate_array.c
	$(CC) $($CFLAGS) $< -o $@

.PHONY: clean

clean:
	-rm \
	rotate_array \
	find_odd_number_in_array\
	find_binary_gap