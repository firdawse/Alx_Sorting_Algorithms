#include "sort.h"

/**
 * swap - Swaps two nodes of doubly linked list
 *
 * @node: node to change
 * @list: double link list current
 */
void swap(listint_t **node, listint_t **list)
{
	listint_t *prev, *next;

	if (!node || !*node || !(*node)->next)
		return;

	prev = (*node)->prev;
	next = (*node)->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	next->prev = prev;
	(*node)->prev = next;
	(*node)->next = next->next;

	if (next->next)
		next->next->prev = *node;

	next->next = *node;
	*node = next;
}

/**
 * insertion_sort_list - sorts a doubly linked list with insertion algorithm
 *
 * @list: doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *right_list, *swapped;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	current = *list;
	while (current && current->next)
	{
		if (current->n > current->next->n)
		{
			swapped = current;

			swap(&swapped, list);
			print_list(*list); /* to print the change occurred */
			current = swapped;
			right_list = swapped;

			while (right_list && right_list->prev)
			{
				/* traverse the right side of the linked list */
				if (right_list->n < right_list->prev->n)
				{
					swapped = right_list->prev;

					swap(&(swapped), list);

					print_list(*list);
					right_list = swapped->next;
				}

				right_list = right_list->prev;
			}
		}
		current = current->next;
	}
}

