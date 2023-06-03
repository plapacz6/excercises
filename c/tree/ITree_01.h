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

ITree *ITree_create_with_value(ITreeValueType val);
void ITree_destroy(ITree* it);
void ITree_insert(ITree *it, ITreeNode *parent, ITreeValueType val);
void ITree_search_through(ITree *it, void action(ITreeValueType* pval, void* arg), void* arg);
void ITree_print_elements(ITree *it, void print_action(ITreeValueType* pval, void* arg));

#endif // ITree_01_H