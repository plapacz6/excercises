#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define NOT_EXIST ((size_t)(-1))
#define TREE_SIZE (100)
typedef struct tree {
    size_t node[TREE_SIZE];
    size_t parents[TREE_SIZE];
    size_t tree_size;

    bool valid_children_info;
    size_t *children_parent[TREE_SIZE];
    size_t count_children_parent[TREE_SIZE];
    size_t count_children_parent_B[TREE_SIZE];
} tree;

tree *tree_create() {
    tree *tr = (tree*)malloc(sizeof(tree));
    if(!tr) {
        fprintf(stderr, "lack of memory %d\n", __LINE__);
        exit(1);
    }
    memset(tr->node, 0, TREE_SIZE * sizeof(size_t));

    // memset(tr->parents, NOT_EXIST, TREE_SIZE * sizeof(size_t));
    for(size_t *it = tr->parents; it < tr->parents + TREE_SIZE; it++) {
        *it = NOT_EXIST;
    }

    tr->tree_size = 0;

    //for 1st run of generate_children_info()
    memset(tr->children_parent, 0, TREE_SIZE * sizeof(size_t));

    return tr;
}

void tree_helping_release_alocated_memory_for_childen(tree* ptree) {
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(ptree->children_parent[i]) {
            free(ptree->children_parent[i]);
            ptree->children_parent[i] = NULL;
        }
    }
}

size_t tree_helping_generate_childen_info(tree* t) {

    //relasing previosuly alocated memory
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(t->children_parent[i]) {
            free(t->children_parent[i]);
            t->children_parent[i] = NULL;
        }
    }

    memset(t->children_parent, 0, TREE_SIZE * sizeof(size_t));
    //memset(t->count_children_parent, 0, TREE_SIZE * sizeof(size_t));
    for(size_t* it = t->count_children_parent; it < t->count_children_parent + TREE_SIZE; it++) {
        *it = 0;
    }

    printf("%s\n", "------------------------------1");
    //counting children of parent
    for(size_t in = 0; in < TREE_SIZE; in++) {
        if(t->parents[in] != NOT_EXIST ) {
            (t->count_children_parent[t->parents[in]])++;
            printf("node:%lu has parent:%lu\n", t->node[in], t->parents[in]);
        }
    }

    //copy helping array
    for(size_t* it1 = t->count_children_parent_B, *it2 = t->count_children_parent;
            it1 < t->count_children_parent_B + TREE_SIZE;
            it1++, it2++) {
        *it1 = *it2;
    }

    printf("%s\n", "------------------------------2");
    //preparing place for children of parent
    for(size_t ip = 0; ip < TREE_SIZE; ip++) {
        if(t->count_children_parent[ip]) {
            printf("t->count_children_parent[%lu]:%lu\n", ip, t->count_children_parent[ip]);

            t->children_parent[ip] = (size_t*)malloc((t->count_children_parent[ip]) * sizeof(size_t));

            if(!t->children_parent[ip]) {
                fprintf(stderr, "lack of memory %d, required memory: %lu bytes\n", __LINE__,
                        t->count_children_parent[ip] * sizeof(size_t));
                exit(1);
            }
            //memset(t->children_parent[ip], NOT_EXIST, t->count_children_parent[ip] * sizeof(size_t));
            for(size_t *it = t->children_parent[ip];
                    it != t->children_parent[ip] + t->count_children_parent[ip]; it++) {
                *it = NOT_EXIST;
            }
        }
    }
    printf("%s\n", "------------------------------3");
    //copying children to place prepared for them in parent
    for(size_t icp = 0; icp < TREE_SIZE; icp++) {
        if(t->count_children_parent[icp] != 0) {
            for(size_t ni = 0; ni < TREE_SIZE; ni++) {
                if(icp == t->parents[ni]) {
                    t->children_parent[icp][t->count_children_parent_B[icp] - 1] = ni; //t->node[ni]; not value but idx
                    t->count_children_parent_B[icp]--;
                }
            }
        }
    }

    t->valid_children_info = true;
}

void tree_destroy(tree* ptree) {
    printf("%s\n", "------------------------------5");
    //freeing alocated memory
    if(ptree) {
        tree_helping_release_alocated_memory_for_childen(ptree);
        free(ptree);
    }    
}

void tree_insert_node(tree *ptree, size_t parent, size_t new_node) {
    ptree->tree_size++;
    if(ptree->tree_size > TREE_SIZE) {
        fprintf(stderr, "tree capacity exceeded\n");
        exit(1);
    }
    ptree->node[ptree->tree_size - 1] = new_node;
    ptree->parents[ptree->tree_size - 1] = parent;

    ptree->valid_children_info = false;    
    //tree_helping_generate_childen_info(ptree);
    
}

void tree_print(tree *ptree) {
    if(!ptree->valid_children_info) {
        tree_helping_generate_childen_info(ptree);
    }
    printf("%s\n", "------------------------------4");
    //printing parent and its children
    for(size_t i = 0; i < TREE_SIZE; i++) {
        if(ptree->children_parent[i] != NULL) {
            //printf(" c_cp:%lu, cp:%p : ", count_children_parent[i], children_parent[i]);
            printf("node:%lu:\n\tchildren: ", i);
            for(size_t k = 0; k < ptree->count_children_parent[i]; k++) {
                printf("idx:%lu:[%lu], ", ptree->children_parent[i][k],
                       ptree->node[ptree->children_parent[i][k]]);
                //printf(" c_cp:%lu, cp:%p", count_children_parent[i], children_parent[i]);
            }
            printf("%s", "\n");
        }
    }
}



void test_tree_print1(tree* ptree, size_t n) {
    printf("%s:\n", "node");
    for(size_t i = 0; i < n; i++) {
        printf("[%lu]", ptree->node[i]);
    }
    printf("%s","\n");
    printf("%s:\n", "parents");
    for(size_t i = 0; i < n; i++) {
        printf("[%lu]", ptree->parents[i]);
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
    test_tree_print1(ptr_t1, 10);
    tree_print(ptr_t1);
    tree_destroy(ptr_t1);

    return 0;
}