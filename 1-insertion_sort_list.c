#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *tmp;

	if (!list)
		return;

	current_node = *list;

	while (current_node)
	{
		while (current_node->next && (current_node->n > current_node->next->n))
		{
			/* Swap current node and next node */
			tmp = current_node->next;
			current_node->next = tmp->next;
			tmp->prev = current_node->prev;

			if (current_node->prev)
				current_node->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = current_node;

			current_node->prev = tmp;
			tmp->next = current_node;

			if (tmp->prev)
				current_node = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		current_node = current_node->next;
	}
}
