#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define TREE_SIZE (100)
typedef struct tree {
    size_t node[TREE_SIZE];
    size_t parents[TREE_SIZE];
    size_t tree_size;
} tree;

tree *tree_create() {
    tree *tr = (tree*)malloc(sizeof(tree));
    if(!tr) {
        fprintf(stderr, "lack of memory %d\n", __LINE__);
        exit(1);
    }
    memset(tr->node, 0, TREE_SIZE);

    //memset(tr->parents, (size_t)(-1), TREE_SIZE);   //because of working on  char not work here (on unsinged long)
    // for(size_t i = 0; i < TREE_SIZE; i++){
    //     tr->parents[i] = (size_t)(-1);
    // }
    for(size_t *it = tr->parents; it < tr->parents + TREE_SIZE; it++) {
        *it = (size_t)(-1);
    }

    tr->tree_size = 0;
    return tr;
}

size_t tree_find_parent(tree* ptr_tree, size_t n) {
    return ptr_tree->parents[n];
}

void tree_insert_node(tree *ptr_tree, size_t parent, size_t new_node) {
    ptr_tree->tree_size++;
    if(ptr_tree->tree_size > TREE_SIZE) {
        fprintf(stderr, "tree capacity exceeded\n");
        exit(1);
    }
    ptr_tree->node[ptr_tree->tree_size - 1] = new_node;
    ptr_tree->parents[ptr_tree->tree_size - 1] = parent;
}

size_t tree_parent_childs_count(tree *ptr_tree, size_t parent) {
    size_t n = 0;
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(ptr_tree->parents[i] == parent) {
            n++;
        }
    }
    return n;
}

void tree_print(tree *ptr_tree) {
    size_t *parents_children[TREE_SIZE];
    size_t parents_children_no[TREE_SIZE];
    // size_t parents_children_no1[TREE_SIZE];

    //memset(parents_children, 0, TREE_SIZE);
    //memset(parents_children_no, 0, TREE_SIZE);  //don't work correctly for unsinged long
    // for(size_t i = 0; i < TREE_SIZE; i++){
    //     parents_children_no[i] = 0;
    //     //parents_children[i] = 0;
    // }
    for(size_t* it = parents_children_no; it < parents_children_no + TREE_SIZE; it++) {
        *it = 0;
    }
    printf("%s\n", "------------------------------1");
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(ptr_tree->parents[i] != (size_t)(-1) ) {
            (parents_children_no[ptr_tree->parents[i]])++;
            printf("node:%lu has parent:%lu\n", ptr_tree->node[i], ptr_tree->parents[i]);
        }
        else {
            //printf("zeros parents_children[%lu]\n", i);
            parents_children[i] = 0;  //instead of memset
            //printf("%s\n", "++++++++");
        }
    }
    
    // /* vvv- lub wypelnic parents_children_no  wartosciami (-1) */
    // for(size_t* it1 = parents_children_no1, *it2 = parents_children_no;
    //         it1 < parents_children_no1 + TREE_SIZE;
    //         it1++, it2++) {
    //     *it1 = *it2;
    // }

    printf("%s\n", "------------------------------2");
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(parents_children_no[i]) {
            printf("parents_children_no[%lu]:%lu\n", i, parents_children_no[i]);
            //parents_children[i] = (size_t*)malloc((parents_children_no[i]) * sizeof(size_t));
            
            parents_children[i] = (size_t*)malloc((parents_children_no[i] + 1) * sizeof(size_t));
            parents_children[i][parents_children_no[i]] = (size_t)(-1);
            
            if(!parents_children[i]) {
                fprintf(stderr, "lack of memory %d, required memory: %lu bytes\n", __LINE__, parents_children_no[i] * sizeof(size_t));
                exit(1);
            }
            memset(parents_children[i], (size_t)(-1), (parents_children_no[i] + 1) * sizeof(size_t));
        }
    }
    printf("%s\n", "------------------------------3");
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(ptr_tree->parents[i] != (size_t)(-1)) {
            size_t idx = parents_children_no[i];
            parents_children_no[i]--;

            size_t ii = ptr_tree->parents[i];
            size_t nd = ptr_tree->node[i];
            parents_children[ii][idx] = nd;
            //parents_children[ptr_tree->parents[i]][idx] = ptr_tree->node[i];
        }        
    }
    printf("%s\n", "------------------------------4");
    for(size_t i = 0; i < TREE_SIZE; i++) {
        printf("%lu:\n", i);
        //for(size_t k = 0; k < parents_children_no[i]; k++) {
        
        for(size_t k = 0; parents_children[i][k] != (size_t)(-1); k++) {
        
            printf("%lu, ", parents_children[i][k]);
        }
        printf("%s", "\n");
    }
    printf("%s\n", "------------------------------5");
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(parents_children[i]) {
            free(parents_children[i]);
            parents_children[i] = NULL;
        }
    }
}

void tree_destroy(tree* ptr_tree) {
}

int main() {
    tree *ptr_t1 = tree_create();

    tree_insert_node(ptr_t1, 0, 1);
    tree_insert_node(ptr_t1, 0, 2);
    for(size_t i = 1; i < 3; i++) {
        for(size_t j = 6; j < 9; j++) {
            printf("main: i:%lu, j:%lu\n", i, j);
            tree_insert_node(ptr_t1, i, j);
        }
    }
    tree_print(ptr_t1);
    tree_destroy(ptr_t1);

    return 0;
}