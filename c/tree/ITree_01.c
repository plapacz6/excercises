#include <stdlib.h>
#include <stdbool.h>
#include "ITree_01.h"

ITree *ITree_create() {
    ITree *it = malloc(sizeof(ITree));
    if(!it) {
        return NULL;
    }
    it->root = NULL;
    return it;
}

void ITree_destroy(ITree* it) {
    if(it) {
        if(it->root) {

        }
        free(it);
    }
}

void ITree_insert(ITreeNode *itn, ITreeNode *parent, ITreeValueType val) {
    IList_push_back(itn->parent->children, val);
}

void ITree_print(ITree *it) {
}
