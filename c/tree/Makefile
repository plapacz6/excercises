all: Test_ITree_01

CFLAGS=	-g3 -std=c11

Test_ITree_01: Test_ITree_01.o ITree_01.o IList.o
	$(CC) $(CFLAGS) $^ -o Test_ITree_01
Test_ITree_01.o: Test_ITree_01.c ITree_01.h IList.h IList_cfg.h
	$(CC) $(CFLAGS) $< -c	
ITree_01.o: ITree_01.c ITree_01.h IList.h IList_cfg.h
	$(CC) $(CFLAGS) $< -c	
IList.o: IList.c IList.h IList_cfg.h
	$(CC) $(CFLAGS) $< -c


tree__with_array : tree__with_array_1.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm tree__with_array a.out Test_ITree_01 *.o
