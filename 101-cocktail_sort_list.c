#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: the left node to swap
 * @right: the right node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
	left->prev->next = right;
	else
	*list = right;

	if (right->next)
	right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using Cocktail Shaker Sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start;
	listint_t *end;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (swapped)
	{
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
			else
				start = start->next;
		}
		end = start;

		if (!swapped)
			break;

		swapped = 0;
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	}
}
