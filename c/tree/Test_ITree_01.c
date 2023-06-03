#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "ITree_01.h"

void print_action(ITreeValueType *pval, void* sep) {
    printf("%s[%lu]", (char*)sep, *pval);
}

int main() {

    ITree *it = ITree_create_with_value(10);
    assert(it != NULL);
    assert(it->root != NULL);
    assert(it->root->children != NULL);
    assert(it->root->children->first == NULL);
    assert(it->root->val == 10);
    assert(it->curr == it->root);
    assert(it->is_curr_leaf == true);

    ITree_insert(it, it->root, 11);
    assert(it->root->children->last->val != NULL);
    assert(it->root->children->last->val->parent == it->root);
    assert(it->root->children->last->val->val == 11);
    assert(it->curr == it->root);
    assert(it->is_curr_leaf == false);

    ITree_insert(it, it->root, 12);
    assert(it->root->children->last->val != NULL);
    assert(it->root->children->last->val->parent == it->root);
    assert(it->root->children->last->val->val == 12);
    assert(it->curr == it->root);
    assert(it->is_curr_leaf == false);

    printf("%s", "\n");
    ITree_print_elements(it, print_action);
    printf("%s", "\n");

    int ret = 0;
    ret = ITree_down(it);
    assert(ret == 0);
    assert(it->curr == it->root->children->first->val);
    assert(it->is_curr_leaf == true);

    ret = ITree_down(it);
    assert(ret == -1);
    assert(it->curr == it->root->children->first->val);
    assert(it->is_curr_leaf == true);

    ITree_destroy(it);
    return 0;
}