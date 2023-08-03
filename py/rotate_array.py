#rotate array A by K position in Right direction
def solution(A, K):
    if A == None or len(A) < 2:
        return A
    shiftR = 0    
    while shiftR < K:
        tmp = A[len(A) - 1]
        i = len(A) - 1
        while i > 0:
            A[i] = A[i - 1]
            i -= 1
        A[0] = tmp
        shiftR += 1
        #print("{}", A)
    #print("{}", A)
    return A
