#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "IList.h"

int main(int argc, char* argv[static argc])
{
    IList* il = IList_new();

    assert(il != NULL);
    assert(il->first == NULL);
    assert(il->last == NULL);

    int x = 11;
    IList_push_back(il, x);
    assert(il->first->val == x);
    assert(il->last->val == x);

    int y = 12;
    IList_push_back(il, y);
    assert(il->first->val == x);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    assert(il->last->val == y);
    //printf("val: %d, y: %d\n", il->last->val, y);

    y = 13;
    IList_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    y = 14;
    IList_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    y = 12;
    IListNode *node =
        IList_find_node(12, il->first);
    assert(node != NULL);
    assert(node->val == 12);
    assert(node->next->val == 13);

    IListNode *node2 = IList_remove_node(il, node);
    assert(node2 != NULL);
    assert(node2 = node);

    IListNode *node3 = IList_find_node(11, il->first);
    assert(node3 != NULL);
    assert(node3->val == 11);
    assert(node3->next->val == 13);
    free(node2);
    node = NULL;
    node = IList_find_node(12, il->first);
    assert(node == NULL);

    IList_delete(il);

    return 0;
}
