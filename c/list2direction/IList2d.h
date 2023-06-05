#ifndef ILIST_2D_H
#define ILIST_2D_H

#include "IList2d_cfg.h"

typedef struct IList2dNode
{
    IList2dValueType val;
    struct IList2dNode* next;
    struct IList2dNode* prev;
} IList2dNode;

typedef struct IList2d
{
    IList2dNode *first;
    IList2dNode *last;
} IList2d;

IList2d* IList2d_new(void);
void IList2d_delete(IList2d* il);
void IList2d_push_back(IList2d* il, IList2dValueType val);

#endif // ILIST_2D_H