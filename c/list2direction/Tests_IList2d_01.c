#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "IList2d.h"

int main(int argc, char* argv[static argc])
{
    IList2d* il = IList2d_new();

    assert(il != NULL);
    assert(il->first == NULL);
    assert(il->last == NULL);

    int x = 11;
    IList2d_push_back(il, x);
    //list: 11
    assert(il->first->val == x);
    assert(il->last->val == x);
    assert(il->first->next == NULL);
    assert(il->last->next ==NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == NULL);

    int y = 12;
    IList2d_push_back(il, y);
    //list: 11, 12
    assert(il->first->val == x);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);
    assert(il->first->next == il->last);
    assert(il->first->prev == NULL);
    assert(il->last->prev == il->first);

    assert(il->last->val == y);
    //printf("val: %d, y: %d\n", il->last->val, y);

    y = 13;
    IList2d_push_back(il, y);
    //list: 11, 12, 13
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == il->first->next);

    y = 14;
    IList2d_push_back(il, y);
    //list: 11, 12, 13, 14
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == il->first->next->next);

    y = 12;
    IList2dNode *node =
        IList2d_find_node(12, il->first);
    assert(node != NULL);
    assert(node->val == 12);
    assert(node->next->val == 13);

    IList2dNode *node2 = IList2d_remove_node(il, node);
    //list: 11, 13, 14
    assert(node2 != NULL);
    assert(node2 = node);
    assert(node2->prev == NULL);
    assert(node2->next == NULL);
    free(node2);
    node2 = NULL;

    IList2dNode *node3 = IList2d_find_node(11, il->first);
    assert(node3 != NULL);
    assert(node3->val == 11);
    assert(node3->next->val == 13);    
    
    node = IList2d_find_node(12, il->first);
    assert(node == NULL);

    node = IList2d_find_node(14, il->first);
    assert(node != NULL);
    assert(node->val == 14);
    assert(node->next == NULL);

    //removing last
    node2 = IList2d_remove_node(il, node);
    //list: 11, 13
    assert(node2 == node);
    assert(node2->prev == NULL);
    assert(node2->next == NULL);
    
    node3 = IList2d_find_node(13, il->first);
    assert(node3->val == 13);
    assert(node3->prev != NULL);
    assert(node3->prev->val == 11); 
    assert(node3->next == NULL);    
    free(node2);

    node = IList2d_find_node(11, il->first);
    assert(node->val == 11);
    assert(node->prev == NULL);
    assert(node->next->val == 13);
    
    //removing first
    node2 = IList2d_remove_node(il, node);
    //list: 13
    assert(node2->val == 11);
    assert(node2->prev == NULL);
    assert(node2->next == NULL);
    free(node2);
    node3 = IList2d_find_node(11, il->first);
    assert(node3 == NULL);

    IList2d_delete(il);

    return 0;
}
