/*
rotate array to the right K times
N - size of A
A is of size 0..100
elements of A have value -1000..1000
*/

#include<stdlib.h>
struct Results {
  int *A;
  int N;
};
struct Results solution(int A[], int N, int K) {    
    struct Results result;
    result.A = A;
    result.N = N;    
    if(K % N) {
        int B[N];
        for(size_t i = 0; i < N; i++){
            B[i] = A[i];
        }                
        for(size_t i = 0; i < N; i++){        
            A[(i + K) % N] = B[i];
        }
    }
    return result;
}

