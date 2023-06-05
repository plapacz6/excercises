#include <stdlib.h>
#include <stdbool.h>
#include "ITree_01.h"

ITreeNode *ITreeNode_create();
void ITreeNode_destroy(ITreeNode *itn);
void ITreeNode_search_through(ITreeNode start[static 1],
                              void action(ITreeValueType* pval, void* arg), void* arg);

ITree *ITree_create_with_value(ITreeValueType val) {
    ITree *it = malloc(sizeof(ITree));
    if(!it) {
        return NULL;
    }
    it->root = ITreeNode_create();
    if(!it->root) {
        return NULL;
    }
    it->root->parent = NULL;
    it->root->val = val;
    it->curr = it->root;    
    it->is_curr_leaf = true;
    return it;
}

ITreeNode *ITreeNode_create() {
    ITreeNode *itn = malloc(sizeof(ITreeNode));
    if(!itn) {
        return NULL;
    }
    //int->parent = NULL;
    itn->children = IList2d_new();
    if(!itn->children) {
        free(itn);
        return NULL;
    }
    itn->curr_child = NULL;    
    return itn;
}

//TODO: add callback to optionaly destroy value of ITreeNode
void ITreeNode_destroy(ITreeNode itn[static 1]) {
    while(itn->children->first) {
        //recursive freeing of nested nodes
        IList2dNode *iln = itn->children->first->next;
        ITreeNode_destroy(itn->children->first->val);
        free(itn->children->first);
        itn->children->first = iln;
    }
    IList2d_delete(itn->children);
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
    if(!itn) {
        exit(1);
    }
    itn->val = val;
    itn->parent = parent;
    IList2d_push_back(parent->children, itn);
    if(it->curr == parent) {
        it->is_curr_leaf = false;
    }
}

void ITreeNode_search_through(ITreeNode start[static 1],
                              void action(ITreeValueType* pval, void* arg), void* arg) {
    IList2dNode *tmp = start->children->first;
    while(tmp) {
        ITreeNode_search_through(tmp->val, action, arg);
        tmp = tmp->next;
    }
    action(&start->val, arg);
}

void ITree_search_through(ITree *it, void action(ITreeValueType* pval, void* arg), void* arg) {
    ITreeNode_search_through(it->root, action, arg);
}

void ITree_print_elements(ITree *it, void print_action(ITreeValueType* pval, void* arg)) {
    ITree_search_through(it, print_action, "");
}

int ITree_up(ITree *it) {
    if(!it->curr->parent){
        return -1;
    }
    //it->curr_child =  //not neccessary because set previously (we go frist fron up to down)
    it->curr = it->curr->parent;    
    it->is_curr_leaf = false;    
    return 0;
}

int ITree_down(ITree *it) {
    if(!it->curr->children->first) {
        return -1;
    }
    it->curr->curr_child = it->curr->children->first;
    it->curr = it->curr->children->first->val;    
    if(!it->curr->children->first) {
        it->is_curr_leaf = true;
    }
    else {
        it->is_curr_leaf = false;
    }
    return 0;
}

int ITree_right(ITree *it){
    // if(!it->curr->parent){
    //     return -1;
    // }
    // if(!it->curr->parent->curr_child->next){
    //     return -1;
    // }
    // it->curr = it->curr->parent->curr_child->next->val;
    // it->curr->parent->curr_child = it->curr->curr_child->next;
    // if(!it->curr->children->first){
    //     it->is_curr_leaf = true;
    // }
    // else {
    //     it->is_curr_leaf = false;
    // }

    // return 0;
}   

int ITree_left(ITree *it){
//     if(!it->curr->parent){
//         return -1;
//     }    
//    if(!it->curr->parent->curr_child->prev){
//         return -1;
//     }
//     it->curr = it->curr->parent->curr_child->prev->val;
//     it->curr->parent->curr_child = it->curr->curr_child->prev;
//     if(!it->curr->children->first){
//         it->is_curr_leaf = true;
//     }
//     else {
//         it->is_curr_leaf = false;
//     }

//     return 0;
}

ITreeValueType ITree_get_curr_val(ITree *it) {
    return it->curr->val;
}
