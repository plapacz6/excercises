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
    assert(il->first->val == x);
    assert(il->last->val == x);
    assert(il->first->next == NULL);
    assert(il->last->next ==NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == NULL);

    int y = 12;
    IList2d_push_back(il, y);
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
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == il->first->next);

    y = 14;
    IList2d_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);
    assert(il->first->prev == NULL);
    assert(il->last->prev == il->first->next->next);

    IList2d_delete(il);

    return 0;
}
