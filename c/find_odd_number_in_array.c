/*
Find odd number in not empty array
assumptions:
A is not empty
N (size of array) from range 1..1 000 000
elements of A have value from range 1..1 000 000 000
there is only one odd number in A
*/
#include <stdlib.h>
//#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "list2direction/IList2d.h"

int solution1(int A[], int N) {
    size_t j = 0;
    size_t i = 0;
    int counter = 0;
    for(i = 0; i < N; i++) {
        counter = 0;
        for(j = 0; j < N; j++) {
            if(A[i] == A[j]) {
                counter++;
            }
        }
        if(counter == 1) {
            //printf("j: %lu\n", j);
            break;
        }
    }
    return A[i];
}

int solution2(int A[], int N) {
    /*
        NOT WORK
    */
    int *pM = malloc(((N / 2) + 1) * sizeof(int));
    if(!pM) {
        return -1;
    }
    size_t *oddidxs = malloc(((N / 2) + 1) * sizeof(size_t));
    if(!oddidxs) {
        free(pM);
        return -1;
    }
    size_t j = 0;
    size_t i = 0;
    size_t pMsize = 0;
    size_t oddidxs_size = 0;
    int oddidx = 0;
    bool isodd = true;

    for(i = 0; i < N; i++) {
        isodd = true;
        for(j = 0; j < pMsize; j++) {
            if(*(pM + j) == A[i]) {    //if already encountered
                isodd = false;
                //pop from stack
                oddidxs_size--;
                oddidx = oddidxs[oddidxs_size]; //stack ready for new value
                break;
            }
        }
        /*
        there may be a sequence of odd numbers at the beginning
         and somewhere between them is the real one
         and it is not known in which order they will be encountered
         and here we remove sequentially as they were encountered
        */
        if(isodd) {
            *(pM + pMsize) = A[i];
            pMsize++;
            oddidx = i;
            //push on stack
            oddidxs[oddidxs_size] = oddidx;
            oddidxs_size++;                      //stack ready for new value
        }
    }
    if(pM) {
        free(pM);
    }
    if(oddidxs) {
        free(oddidxs);
    }
    return A[oddidx];
}

int solution3(int A[], int N) {
    /*
        NOT WORK

        similiar solution2 but instead array list applayed
    */
    IList2d* mem_list = IList2d_new();
    if(!mem_list) {
        return -1;
    }

    size_t i = 0;
    size_t pMsize = 0;
    int oddidx = 0;
    bool isodd = true;
    IList2dNode *node = NULL;

    for(i = 0; i < N; i++) {
        isodd = true;
        node = IList2d_find_node(A[i], mem_list->first);
        if(node) {
            isodd = false;
            //oddidx = indexes
            /*
            there is a need to remember previous indices,
            but the order of index elements encountered as yet unpaired
            must be equal to the order of their pairs
            */
        }
        if(isodd) {
            IList2d_push_back(mem_list, A[i]);
            oddidx = i;
        }
    }
    IList2d_delete(mem_list);
    return A[oddidx];
}

int solution4(int A[], int N) {
    /*
    add when encountered
    and remove when a pair is encountered
    a bidirectional list is needed for this
    because in the array you would have to rewrite the entire array each time
    you delete an element
    */
    IList2d* mem_list = IList2d_new();
    if(!mem_list) {
        return -1;
    }

    size_t i = 0;
    IList2dNode *node = NULL;

    for(i = 0; i < N; i++) {
        node = IList2d_find_node(A[i], mem_list->first);
        if(node) {
            IList2d_remove_node(mem_list, node);
            free(node);
            //node = NULL;
        }
        else {
            IList2d_push_back(mem_list, A[i]);
        }
    }
    int val = mem_list->first->val;
    assert(mem_list->first == mem_list->last);
    assert(mem_list->first->next == NULL);
    IList2d_delete(mem_list);
    return val;
}

int comp_int(const void* a, const void* b) {
    return *(int*)a < *(int*)b;
}
int solution5(int A[], int N) {
    assert(A != NULL);
    assert(N > 0);

    qsort(A, N, sizeof(int), comp_int);

    size_t i = 0;
    size_t j = 1;
    size_t counter = 0;
    int val = A[0];
    if(N == 1) {
        return val;
    }
    for( ; j < N; i++, j++) {
        if(A[i] != A[j]) {
            if(counter == 1) {
                val = A[i];
                break;
            }
            counter = 1;
        }
        else {
            counter++;
        }
    }
    return val;
}

void test_and_print(int nr, int* A, int N, int val, int solution(int* A, int N)) {
    printf("solutioni%d(... val: %d) -> ", nr, val);
    assert(solution3(A, N) == val);
    printf("%d\n", solution(A, N));
}
int main() {

    srand(time(NULL));

    enum {N1 = 1025, N2 = 10001};
    for(size_t j = 0; j < 10; j++) {
        {
            int tbl1[N1];
            for(size_t i = 0; i < N1/2; i++) {
                tbl1[i] = rand() % 1000;
            }
            tbl1[N1/2] = 1009;
            for(size_t i = 0; i < N1/2; i++) {
                tbl1[i + N1/2 + 1] = tbl1[i];
            }
            test_and_print(1, tbl1, N1, 1009, solution1);
            //test_and_print(2, tbl1, N1, 1009, solution2);
            //test_and_print(3, tbl1, N1, 1009, solution3);
            test_and_print(4, tbl1, N1, 1009, solution4);
            test_and_print(5, tbl1, N1, 1009, solution5);

        }
        {
            int tbl1[N2];
            for(size_t i = 0; i < N2/4; i++) {
                tbl1[i] = rand() % 1000;
            }
            tbl1[N2/4] = 1029;
            for(size_t i = 0; i < N2/4; i++) {
                tbl1[i + (1 * N2/4) + 1] = tbl1[i];
                tbl1[i + (2 * N2/4) + 1] = tbl1[i];
                tbl1[i + (3 * N2/4) + 1] = tbl1[i];
            }
            test_and_print(1, tbl1, N2, 1029, solution1);
            //test_and_print(2, tbl1, N2, 1029, solution2);
            //test_and_print(3, tbl1, N2, 1029, solution3);
            test_and_print(4, tbl1, N2, 1029, solution4);
            test_and_print(5, tbl1, N2, 1029, solution5);

        }
    }

    return EXIT_SUCCESS;
}
