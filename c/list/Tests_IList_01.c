#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "IList_01.h"


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

    IList_delete(il);

    return 0;
}
