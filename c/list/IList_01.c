#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "IList_01.h"


IList* IList_new(void)
{
    IList* il = malloc(sizeof(IList));
    if(!il) {
        return NULL;
    }
    il->first = NULL;
    il->last = NULL;
    return il;
}

void IList_delete(IList* const il)
{
    IListNode *tmp = NULL;
    while(il->first) {
        tmp = il->first->next;
        free(il->first);
        il->first = tmp;
    }
    if(il) {
        free(il);
    }
}

void IList_push_back(IList* const il, const int val)
{
    if(!il->first) {
        il->first = malloc(sizeof(IListNode));
        if(!il->first) {
            exit(1);
        }
        il->first->next = NULL;
        il->first->val = val;
        il->last = il->first;
    }
    else {
        il->last->next = malloc(sizeof(IListNode));
        if(!il->last->next) {
            exit(1);
        }
        il->last->next->val = val;
        il->last->next->next = NULL;
        il->last = il->last->next;
    }
}

