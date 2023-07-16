#ifndef ILIST_H
#define ILIST_H

#include "IList_cfg.h"

typedef struct IListNode
{
    IListValueType val;
    struct IListNode* next;
} IListNode;

typedef struct IList
{
    IListNode *first;
    IListNode *last;
} IList;

/**
 * @brief creates IList object and retur pointer to it
 * 
 * @return IList* 
 */
IList* IList_new(void);

/**
 * @brief delete IList object and remove all their nodes
 *        but not released memory allocated by their value 
 *        (if any was before added value to the list)
 * 
 * @param il 
 */
void IList_delete(IList* il);

/**
 * @brief push back value val to the end of list il
 * 
 * @param il 
 * @param val 
 */
void IList_push_back(IList* il, const_IListValueType val);

/**
 * @brief finds first occurence of node with value val starting from 
 * node start_iln
 * 
 * @param val 
 * @param start_iln   
 * @return IListNode* node with value val
 *                    NULL if not found
 */
IListNode* IList_find_node(const_IListValueType val, IListNode *start_iln);

/**
 * @brief remove from IList il node pointed by iln
 * 
 * @param il 
 * @param iln 
 * @return IListNode* pointer to removed IListNode
 *         NULL if iln was NULL, or iln was not found in il 
 *         (there was not node with addres equal to iln)
 */
IListNode* IList_remove_node(IList *il, IListNode *iln);

#endif // ILIST_H