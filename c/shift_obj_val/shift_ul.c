#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void shift_ul(size_t* pval) {
    if(*pval == 0x8000000000000000) {
        *pval = 1;
    }
    else {
        *pval <<= 1;
    }
}

int main() {
    size_t val = 1;
    shift_ul(&val);
    assert(val ==  2);
    shift_ul(&val);
    assert(val ==  4);
    shift_ul(&val);
    assert(val ==  8);
    shift_ul(&val);
    assert(val ==  16);
    shift_ul(&val);
    assert(val ==  32);
    shift_ul(&val);
    assert(val ==  64);
    shift_ul(&val);
    assert(val ==  128);
    shift_ul(&val);
    assert(val ==  256);
    shift_ul(&val);
    assert(val ==  512);
    shift_ul(&val);
    assert(val ==  1024);

    val = 0b1000000000000000\
0000000000000000\
0000000000000000\
0000000000000000;
    //printf("%lu - %lu\n", val, 0x8000000000000000uL);
    shift_ul(&val);
    assert(val == 1);
}