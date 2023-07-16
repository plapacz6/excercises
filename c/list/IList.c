#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "IList.h"

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

void IList_push_back(IList* const il, const IListValueType val)
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

IListNode* IList_find_node(const_IListValueType val, IListNode *start_iln) {
    while(start_iln) {
        if(start_iln->val == val) {
            return start_iln;
        }
        start_iln = start_iln->next;
    }
    return NULL;
}

IListNode* IList_remove_node(IList *il, IListNode *iln) {
    if(iln) {
        IListNode *parent = il->first;
        while(parent->next != iln && parent->next != NULL) {
            parent = parent->next;
        };
        if(parent->next == iln) {
            parent->next = iln->next;
            return iln;
        }
        else {
            return NULL;
        }
    }
    return NULL;
}
