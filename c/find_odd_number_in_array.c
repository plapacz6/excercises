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

int solution1(int A[], int N) {  
  size_t j = 0;
  size_t i = 0;
  int counter = 0;  
  for(i = 0; i < N; i++) {                        
      counter = 0;
      for(j = 0; j < N; j++){
          if(A[i] == A[j]){
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
  int *pM = malloc(((N / 2) + 1) * sizeof(int));
  if(!pM){
      return -1;
  }
  size_t j = 0;
  size_t i = 0;  
  size_t pMsize = 0;
  int oddidx = 0;
  bool isodd = true;

  for(i = 0; i < N; i++){
    isodd = true;
    for(j = 0; j < pMsize; j++){
        if(*(pM + j) == A[i]) {
            isodd = false;
            break;
        }
    }
    if(isodd) {
        ++pMsize;
        *(pM + pMsize) = A[i];
        oddidx = i;
    }    
  }
  if(pM){
      free(pM);
  }
  return A[oddidx];
}
