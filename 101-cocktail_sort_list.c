#include <stddef.h>
#include <stdbool.h>
#include "sort.h"

/**
 * dll_adj_swap - swaps two adjacent nodes of a doubly linked list
 * @list: doubly linked list of integers to be sorted
 * @left: node closer to head, right->prev
 * @right: node closer to tail, left->next
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev != NULL)
        left->prev->next = right;
    else
        *list = right;

    if (right->next != NULL)
        right->next->prev = left;

    right->prev = left->prev;
    left->prev = right;
    left->next = right->next;
    right->next = left;

    print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using an cocktail shaker sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    bool swapped;
    size_t size;
    listint_t *current;

    do {
        swapped = false;
        for (current = *list; current->next != NULL; current = current->next) {
            if (current->n > current->next->n) {
                dll_adj_swap(list, current, current->next);
                swapped = true;
            }
        }
        if (!swapped)
            break;

        swapped = false;
        for (current = current->prev, size = 0; current->prev != NULL; current = current->prev) {
            if (current->n < current->prev->n) {
                dll_adj_swap(list, current->prev, current);
                swapped = true;
            } else {
                size++;
            }
        }
    } while (swapped && size != 0);
}
