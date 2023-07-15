/*
Find longest sequence of zeros in binary representation of an integer.
N = 0..2 147 483 647
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// void print(long n){
//     for(size_t i = (8 * 8); i > 0; i--){
//         printf("%c", (n>>(i - 1) & 1) ? '1' : '0');
//     }
//     printf("%c",'\n');
// }

int solution(int N) {    
    long n = (long)N;
    int maxg = 0;
    int cg = 0;
    int rec = false;
    int bit = 0;
    //print(n);

    for(size_t i = 0; i < (8 * 8); i++){
        bit = n>>i & 1;

        if(!rec){
            if(bit){
                rec = true;
            }
        }
        else {
            if(!bit){
                cg++;
            }
            else {                
                if(maxg < cg)
                    maxg = cg;
                    cg = 0;                    
            }
        }
    }
    //printf("%d\n", maxg);
    return maxg;
}
