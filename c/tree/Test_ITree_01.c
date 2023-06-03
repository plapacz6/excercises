#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "ITree_01.h"

int main() {

    ITree *it = ITree_create_with_value(10);
    assert(it != NULL);
    assert(it->root != NULL);    
    assert(it->root->children != NULL);    
    assert(it->root->children->first == NULL);    
    assert(it->root->val == 10);

    ITree_insert(it, it->root, 11);
    assert(it->root->children->last->val != NULL);
    assert(it->root->children->last->val->parent == it->root);
    assert(it->root->children->last->val->val == 11);

    ITree_destroy(it);
    return 0;
}