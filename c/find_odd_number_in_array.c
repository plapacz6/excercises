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

int solution(int A[], int N) {  
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
