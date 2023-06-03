#include <stdlib.h>
#include <stdbool.h>
#include "ITree_01.h"

ITree *ITree_create_with_value(ITreeValueType val) {
    ITree *it = malloc(sizeof(ITree));
    if(!it) {
        return NULL;
    }
    it->root = ITreeNode_create();
    if(!it->root){
        return NULL;
    }
    it->root->parent = NULL;    
    it->root->val = val;
    return it;
}

ITreeNode *ITreeNode_create(){
    ITreeNode *itn = malloc(sizeof(ITreeNode));
    if(!itn){
        return NULL;
    }
    //int->parent = NULL;
    itn->children = IList_new();
    if(!itn->children){
        free(itn);
        return NULL;
    }
    return itn;
}

//TODO: add callback to optionaly destroy value of ITreeNode
void ITreeNode_destroy(ITreeNode *itn){
    while(itn->children->first){
        //recursive freeing of nested nodes
        IListNode *iln = itn->children->first->next;
        ITreeNode_destroy(itn->children->first->val);
        free(itn->children->first);
        itn->children->first = iln;
    }
    IList_delete(itn->children);
    free(itn);
}

void ITree_destroy(ITree* it) {
    if(it) {
        ITreeNode_destroy(it->root);
        free(it);
    }
}

void ITree_insert(ITree *it, ITreeNode *parent, ITreeValueType val) {
    ITreeNode *itn = ITreeNode_create();
    if(!itn){
        exit(1);
    }
    itn->val = val;
    itn->parent = parent;
    IList_push_back(parent->children, itn);
}

void ITree_print(ITree *it) {
}
