#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

typedef struct List
{
    Node *first;
    Node *last;
} List;

List* List_new(void);
void List_delete(List* il);
void List_push_back(List* il, int val);

List* List_new(void)
{
    List* List = malloc(sizeof(List));
    if(!List) {
        return NULL;
    }
    List->first = NULL;
    List->last = NULL;
    return List;
}

void List_delete(List* const il)
{
    Node *tmp = NULL;
    while(il->first) {
        tmp = il->first->next;
        free(il->first);
        il->first = tmp;
    }
    if(il) {
        free(il);
    }
}

void List_push_back(List* const il, const int val)
{
    if(!il->first) {
        il->first = malloc(sizeof(Node));
        if(!il->first) {
            exit(1);
        }
        il->first->next = NULL;
        il->first->val = val;
        il->last = il->first;
    }
    else {
        il->last->next = malloc(sizeof(Node));
        if(!il->last->next) {
            exit(1);
        }
        il->last->next->val = val;
        il->last->next->next = NULL;
        il->last = il->last->next;
    }
}

int main(int argc, char* argv[static argc])
{
    List* il = List_new();

    assert(il != NULL);
    assert(il->first == NULL);
    assert(il->last == NULL);

    int x = 11;
    List_push_back(il, x);
    assert(il->first->val == x);
    assert(il->last->val == x);

    int y = 12;
    List_push_back(il, y);
    assert(il->first->val == x);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    assert(il->last->val == y);
    //printf("val: %d, y: %d\n", il->last->val, y);

    y = 13;
    List_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    y = 14;
    List_push_back(il, y);
    assert(il->last->val == y);
    assert(il->last->next == NULL);
    assert(il->first->next != NULL);

    List_delete(il);

    return 0;
}
