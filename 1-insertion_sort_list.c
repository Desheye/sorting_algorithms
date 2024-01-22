#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using Insertion Sort
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list) {
	listint_t *current = (*list)->next;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (current != NULL) {
        listint_t *temp = current;
        listint_t *prev = current->prev;

       /* listint_t *next_node = NULL;*/

        while (prev != NULL && prev->n > temp->n) {
            /* Swap nodes*/
            if (prev->prev != NULL)
                prev->prev->next = temp;
            temp->prev = prev->prev;
            prev->prev = temp;
            prev->next = temp->next;
            temp->next = prev;

            /* Update next node's prev pointer*/
            if (prev->next != NULL)
                prev->next->prev = prev;

            /* Update the head if necessary*/
            if (temp->prev == NULL)
                *list = temp;

            /* Print the list after each swap*/
            print_list(*list);

            /* Update prev for the next iteration*/
            prev = temp->prev;
        }

        /* Move to the next unsorted element*/
        current = current->next;
    }
}

