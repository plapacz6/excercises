#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define NOT_EXIST ((size_t)(-1))
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
    memset(tr->node, 0, TREE_SIZE * sizeof(size_t));

    // memset(tr->parents, NOT_EXIST, TREE_SIZE * sizeof(size_t));   //because of working on  char not work here (on unsinged long)
    for(size_t *it = tr->parents; it < tr->parents + TREE_SIZE; it++) {
        *it = NOT_EXIST;
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
    size_t *children_parent[TREE_SIZE];
    size_t count_children_parent[TREE_SIZE];
    size_t count_children_parent_B[TREE_SIZE];

    memset(children_parent, 0, TREE_SIZE * sizeof(size_t));
    //memset(count_children_parent, 0, TREE_SIZE * sizeof(size_t));
    for(size_t* it = count_children_parent; it < count_children_parent + TREE_SIZE; it++) {
        *it = 0;        
    }

    printf("%s\n", "------------------------------1");
    //counting children of parent
    for(size_t ni = 0; ni < TREE_SIZE; ni++) {
        if(ptr_tree->parents[ni] != NOT_EXIST ) {
            (count_children_parent[ptr_tree->parents[ni]])++;
            printf("node:%lu has parent:%lu\n", ptr_tree->node[ni], ptr_tree->parents[ni]);
        }    
    }

    //copy helping array
    for(size_t* it1 = count_children_parent_B, *it2 = count_children_parent;
            it1 < count_children_parent_B + TREE_SIZE;
            it1++, it2++) {
        *it1 = *it2;
    }

    printf("%s\n", "------------------------------2");
    //preparing place for children of parent
    for(size_t pi = 0; pi < TREE_SIZE; pi++) {
        if(count_children_parent[pi]) {
            printf("count_children_parent[%lu]:%lu\n", pi, count_children_parent[pi]);

            children_parent[pi] = (size_t*)malloc((count_children_parent[pi]) * sizeof(size_t));

            if(!children_parent[pi]) {
                fprintf(stderr, "lack of memory %d, required memory: %lu bytes\n", __LINE__,
                        count_children_parent[pi] * sizeof(size_t));
                exit(1);
            }
            //memset(children_parent[pi], NOT_EXIST, count_children_parent[pi] * sizeof(size_t));
            for(size_t *it = children_parent[pi];
                    it != children_parent[pi] + count_children_parent[pi]; it++) {
                *it = NOT_EXIST;
            }
        }
    }
    printf("%s\n", "------------------------------3");
    //copying children to place prepared for them in parent                    
    for(size_t cpi = 0; cpi < TREE_SIZE; cpi++){
        if(count_children_parent[cpi] != 0) {
            for(size_t ni = 0; ni < TREE_SIZE; ni++){
                if(cpi == ptr_tree->parents[ni]){
                    children_parent[cpi][count_children_parent_B[cpi] - 1] = ptr_tree->node[ni];
                    count_children_parent_B[cpi]--;
                }
            }
        }
    }

    printf("%s\n", "------------------------------4");
    //printing parent and its children
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(children_parent[i] != NULL) {
            //printf(" c_cp:%lu, cp:%p : ", count_children_parent[i], children_parent[i]);
            printf("%lu:\n", i);
            for(size_t k = 0; k < count_children_parent[i]; k++) {
                printf("%lu, ", children_parent[i][k]);
                //printf(" c_cp:%lu, cp:%p", count_children_parent[i], children_parent[i]);
            }
            printf("%s", "\n");
        }
    }
    printf("%s\n", "------------------------------5");
    //freeing alocated memory
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(children_parent[i]) {
            free(children_parent[i]);
            children_parent[i] = NULL;
        }
    }
}

void tree_destroy(tree* ptr_tree) {
}

void tree_print1(tree* ptr_tree, size_t n) {
    printf("%s:\n", "node");
    for(size_t i = 0; i < n; i++) {
        printf("[%lu]", ptr_tree->node[i]);
    }
    printf("%s","\n");
    printf("%s:\n", "parents");
    for(size_t i = 0; i < n; i++) {
        printf("[%lu]", ptr_tree->parents[i]);
    }
    printf("%s","\n");
}
#undef NOT_EXIST

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
    tree_print1(ptr_t1, 10);
    tree_print(ptr_t1);
    tree_destroy(ptr_t1);

    return 0;
}