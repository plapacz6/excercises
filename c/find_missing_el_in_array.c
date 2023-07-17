/*
find missing integer value in sequence of integers starting from 1 to N + 1
only one value is missing
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

int cmp_int(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}
int solution(int A[], int N) {
    if(!A || N < 1) {
        return 1;
    }
    if(N == 1){
        if(A[0] == 1){
            return 2;
        }
        else {
            return 1;
        }
    }    
    qsort(A, N, sizeof(int), cmp_int);
    
    // for(size_t j = 0; j < N; j++){
    //     printf("[%d]", A[j]);
    // }
    // printf("\n");

    if(A[0] != 1){
        return 1;
    }
    size_t i = 0;
    for( ; i < N - 1; ++i){
        if(A[i + 1] - A[i] > 1){
            break;
        }
    }
    return A[i] + 1;
}

void shuffle_int(int* tbl, size_t size) {
    int tmp;
    size_t idx;
    for(size_t i = 0; i < size; ++i){
        idx = rand() % size;
        tmp = tbl[idx];
        tbl[idx] = tbl[i];
        tbl[i] = tmp;
    }
}
void print_tbl(int *tbl, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        printf("[%d]", tbl[i]);
    }
    printf("%c", '\n');
}
int main(){

        assert(solution(NULL, 0) == 1);
        int tbl1[1] = {2};
        assert(solution(tbl1, 1) == 1);
        tbl1[0] = 1;
        assert(solution(tbl1, 1) == 2);

    srand(time(NULL));    
    for(size_t k = 0; k < 400; ++k) {
        size_t size = rand() % 100000;
        int *tbl = malloc(size * sizeof(int));
        if(!tbl) {
            exit(1);
        }
        for(size_t i = 0; i < size; ++i) {
            tbl[i] = i + 1;
        }
        shuffle_int(tbl, size);        
        int expected = tbl[size - 1];
        int result = solution(tbl, size - 1);

        print_tbl(tbl, size);
        printf("missing: [%d], expeted: [%d]\n", result, expected);

        assert(result == expected);

        if(tbl) {
            free(tbl);
        }
    }

    return EXIT_SUCCESS;
}