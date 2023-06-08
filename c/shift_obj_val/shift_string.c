#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


void shift_string(char *s){
    if(!s) {
        return;
    }
    char tmp = s[0];
    char *p1 = s + 1;
    char *p0 = s;
    while(*p1){
        *p0 = *p1;
        p0++;
        p1++;
    }    
    *p0 = tmp;
}   


int main(){
    char text[] = "alama";
    shift_string(text);
    assert(!strcmp("lamaa", text));
    shift_string(text);
    assert(!strcmp("amaal", text));
    shift_string(text);
    assert(!strcmp("maala", text));
    shift_string(text);
    assert(!strcmp("aalam", text));
    shift_string(text);
    assert(!strcmp("alama", text));
    shift_string(text);
    assert(!strcmp("lamaa", text));

    shift_string(NULL);
    return 0;
}