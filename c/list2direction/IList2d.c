#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "IList2d.h"

IList2d* IList2d_new(void)
{
    IList2d* il = malloc(sizeof(IList2d));
    if(!il) {
        return NULL;
    }
    il->first = NULL;
    il->last = NULL;
    return il;
}

void IList2d_delete(IList2d* const il)
{
    IList2dNode *tmp = NULL;
    while(il->first) {
        tmp = il->first->next;
        free(il->first);
        il->first = tmp;
    }
    if(il) {
        free(il);
    }
}

void IList2d_push_back(IList2d* const il, IList2dValueType val)
{
    if(!il->first) {
        il->first = malloc(sizeof(IList2dNode));
        if(!il->first) {
            exit(1);
        }
        il->first->next = NULL;
        il->first->prev = NULL;
        il->first->val = val;
        il->last = il->first;
    }
    else {
        il->last->next = malloc(sizeof(IList2dNode));
        if(!il->last->next) {
            exit(1);
        }
        il->last->next->val = val;
        il->last->next->next = NULL;
        il->last->next->prev = il->last;
        il->last = il->last->next;
    }
}

IList2dNode* IList2d_find_node(IList2dValueType val, IList2dNode *start_iln) {
    while(start_iln) {
        if(start_iln->val == val) {
            return start_iln;
        }
        start_iln = start_iln->next;
    }
    return NULL;
}

IList2dNode* IList2d_remove_node(IList2d *il, IList2dNode *iln) {
    if(iln) {
        if(!iln->next && !iln->prev) {
            if(il->first == iln){
                assert(il->first == il->last);
                il->first = NULL;
                il->last = NULL;
                return iln;
            }
            else {
                return NULL;
            }
        }
        if(iln->prev) {
            iln->prev->next = iln->next;
        }
        else {
            il->first = iln->next;
        }
        if(iln->next) {
            iln->next->prev = iln->prev;
        }
        else {
            il->last = iln->prev;
        }
        iln->prev = NULL;
        iln->next = NULL;
        return iln;
    }
    return NULL;
}

void IList2d_debug_print(const IList2d *il) {
    IList2dNode *node = il->first;
    printf("%s", "list2d: ");
    while(node) {
        printf("[%i], ", node->val);        
        node = node->next;
    }
    printf("%c", '\n');
}