/*
rotate array to the right K times
N - size of A
A is of size 0..100
elements of A have value -1000..1000
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Results {
    int *A;
    int N;
};
struct Results solution(int A[], int N, int K) {
    struct Results result;
    result.A = A;
    result.N = N;
    if(A == NULL) {
        return result;
    }
    if(K % N) {
        int B[N];
        for(size_t i = 0; i < N; i++) {
            B[i] = A[i];
        }
        for(size_t i = 0; i < N; i++) {
            A[(i + K) % N] = B[i];
        }
    }
    return result;
}

int main() {
    enum {N0 = 0, N1 = 1, N4 = 4, N6 = 6};
    struct Results r;
    {
        r = solution(NULL, 0, 1);
        assert(NULL == r.A);
        assert(0 == r.N);
    }
    {
        int N = N1;
        int A[N1] = {1};
        int ar[N1] = {1};
        int K = 1;
        r = solution(A, N, K);
        assert(!memcmp(ar, r.A, r.N));
    }
    {
        int N = N4;
        int A[N4] = {1, 2, 3, 4};
        int ar[N4] = {1, 2, 3, 4};
        int K = 4;
        r = solution(A, N, K);
        assert(!memcmp(ar, r.A, r.N));
    }
    {
        int N = N4;
        int A[N4] = {1, 2, 3, 4};
        int ar[N4] = {3, 4, 1, 2};
        int K = 2;
        r = solution(A, N, K);
        assert(!memcmp(ar, r.A, r.N));
    }
    {
        int N = N4;
        int A[N4] = {1, 2, 3, 4};
        int ar[N4] = {4, 1, 2, 3};
        int K = 5;
        r = solution(A, N, K);
        assert(!memcmp(ar, r.A, r.N));
    }

    return EXIT_SUCCESS;
}
