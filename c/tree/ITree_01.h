#ifndef ITree_01_H
#define ITree_01_H
#include <stdlib.h>

#include "IList2d.h"

typedef size_t ITreeValueType;

struct ITreeNode {
    ITreeNode *parent;
    IList2d *children;
    ITreeValueType val;
    IList2dNode *curr_child;  //for going through up, left, right, down
};

typedef struct ITree {
    ITreeNode *root;
    
    ITreeNode *curr;
    bool is_curr_leaf;    
} ITree;

ITree *ITree_create_with_value(ITreeValueType val);
void ITree_destroy(ITree* it);
void ITree_insert(ITree *it, ITreeNode *parent, ITreeValueType val);

/**
 * @brief Goes through the tree and executes 'action' on each node
 *
 * @param it      pointer to tree
 * @param action  function to exec
 * @param arg     arguemnt for function
 */
void ITree_search_through(ITree *it, void action(ITreeValueType* pval, void* arg), void* arg);

void ITree_print_elements(ITree *it, void print_action(ITreeValueType* pval, void* arg));

/**
 * @brief Changes currenty pointed node in tree to one level upper
 *
 * @param it   pointer to tree
 * @return int 0 - success,
 *            -1 - currently pointed node is most top (root)
 */
int ITree_up(ITree *it);

/**
 * @brief Changes currently pointed node to point on first child current node
 *
 * @param it     pointer to tree
 * @return int   0 - success
 *               -1 - there is no such node like 'child' in tree
 */
int ITree_down(ITree *it);

/**
 * @brief Sets currently ponted node to next sibling
 * 
 * @param it    pointer to tree
 * @return int  0 - ok
 *              -1 - there is no next sibling
 */
int ITree_left(ITree *it);

/**
 * @brief Sets currently ponted node to previous sibling
 * 
 * @param it    pointer to tree
 * @return int  0 - ok
 *              -1 - there is no previous sibling
 */
int ITree_right(ITree *it);

#endif // ITree_01_H