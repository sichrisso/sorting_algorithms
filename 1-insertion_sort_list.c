#include "sort.h"

/**
 * node_swap - swaps out two nodes if one is greater than the other
 * @first: pointer to 1st node.
 * @second: pointer to 2nd node.
 *
 * Return: void
 */
void node_swap(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * using the insertion sort algorithm.
 *
 * @list: a doubly linked list of integers
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y;

	/* check for nullity */
	if (!list || !*list || !(*list)->next)
		return;
	x = (*list)->next;
	while (x)
	{
		y = x;
		x = x->next;
		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				node_swap(y->prev, y);
				if (!y->prev)
					*list = y;
				print_list((const listint_t *) *list);
			}
			else
				y = y->prev;
		}
	}
}
