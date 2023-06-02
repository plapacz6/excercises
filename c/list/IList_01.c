#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "IList_01.h"

// typedef int IListValueType;

// typedef struct IListNode
// {
//     IListValueType val;
//     struct IListNode* next;
// } IListNode;

// typedef struct IList
// {
//     IListNode *first;
//     IListNode *last;
// } IList;

// IList* IList_new(void);
// void IList_delete(IList* il);
// void IList_push_back(IList* il, int val);

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

int main(int argc, char* argv[static argc])
{
    IList* il = IList_new();

    assert(il != NULL);
    assert(il->first == NULL);
    assert(il->last == NULL);

    int x = 11;
    IList_push_back(il, x);
    assert(il->first->val == x);
    assert(il->last->val == x);

    int y = 12;
    IList_push_back(il, y);
    assert(il->first->val == x);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    assert(il->last->val == y);
    //printf("val: %d, y: %d\n", il->last->val, y);

    y = 13;
    IList_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    y = 14;
    IList_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    IList_delete(il);

    return 0;
}
