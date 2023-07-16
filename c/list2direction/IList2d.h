#ifndef ILIST_2D_H
#define ILIST_2D_H

#include "IList2d_cfg.h"

typedef struct IList2dNode
{
    IList2dValueType val;
    struct IList2dNode* next;
    struct IList2dNode* prev;
} IList2dNode;

typedef struct IList2d
{
    IList2dNode *first;
    IList2dNode *last;
} IList2d;

/**
 * @brief creates IList2d object and return pointer to it
 *
 * @return IList2d*
 */
IList2d* IList2d_new(void);

/**
 * @brief dele whole il list and every is't node
 *        (without releasing allocated memory by them if any was befor conneting
 *         value to the list)
 *
 * @param il
 */
void IList2d_delete(IList2d* il);

/**
 * @brief push value val at the end of list il
 *
 * @param il
 * @param val
 */
void IList2d_push_back(IList2d* il, IList2dValueType val);

/**
 * @brief find first node with value val starting form node start_iln1
 *
 * @param val
 * @param start_iln
 * @return IList2dNode* node with value val
 *                      NULL if not found such node
 */
IList2dNode* IList2d_find_node(IList2dValueType val, IList2dNode *start_iln);

/**
 * @brief removes node iln from list il.
 *        not checks if node iln is node of list il
 *        only checks if iln is not NULL or is not separate node from any list
 *
 * @param il
 * @param iln
 * @return IList2dNode* removed node (with deleted connection with other nodes of list il)
 *         NULL if iln was NULL or was node without connetion to other nodes any list
 */
IList2dNode* IList2d_remove_node(IList2d *il, IList2dNode *iln);

#endif // ILIST_2D_H