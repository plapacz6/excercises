#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "ITree_01.h"

int main() {

    ITree *it = ITree_create();
    assert(it != NULL);
    assert(it->root == NULL);

    ITree_destroy(it);
    return 0;
}