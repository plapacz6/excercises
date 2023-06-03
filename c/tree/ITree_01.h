#ifndef ITree_01_H
#define ITree_01_H
#include <stdlib.h>

#include "IList.h"

typedef size_t ITreeValueType;

struct ITreeNode {
    ITreeNode *parent;
    IList *children;
    ITreeValueType val;
};

typedef struct ITree {
    ITreeNode *root;
} ITree;

ITreeNode *ITreeNode_create();
void ITreeNode_destroy(ITreeNode *itn);
ITree *ITree_create_with_value(ITreeValueType val);
void ITree_destroy(ITree* it);
void ITree_insert(ITree *it, ITreeNode *parent, ITreeValueType val);
void ITree_print(ITree *it);

#endif // ITree_01_H