#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t *node1, listint_t *node2) {
    if (node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list) {
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        /* Forward pass (left to right) */
        for (current = *list; current->next != NULL; current = current->next) {
            if (current->n > current->next->n) {
                swap_nodes(current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        /* Backward pass (right to left) */
        for (; current->prev != NULL; current = current->prev) {
            if (current->n < current->prev->n) {
                swap_nodes(current->prev, current);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}
