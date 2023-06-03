#ifndef ILIST_01_H
#define ILIST_01_H

#include "IList_cfg.h"

typedef struct IListNode
{
    IListValueType val;
    struct IListNode* next;
} IListNode;

typedef struct IList
{
    IListNode *first;
    IListNode *last;
} IList;

IList* IList_new(void);
void IList_delete(IList* il);
void IList_push_back(IList* il, IListValueType val);

#endif // ILIST_01_H