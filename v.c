#include "deck.h"
#include "string.h"

/**
 *swap_ll - swaps value between 2 nodes in doubly linked lists.
 *@left: pointer of doubly linked lists.
 *@right: pointer of doubly linked lists.
 *@list: pointer of doubly linked lists.
 */
void swap_l(deck_node_t *left, deck_node_t *right, deck_node_t **list)
{
	deck_node_t *p, *n;

	p = left->prev;
	n = right->next;
	if (p)
		p->next = right;
	else
		*list = right;
	if (n)
		n->prev = left;
	right->prev = p;
	left->next = n;

	right->next = left;
	left->prev = right;
}

int compare(deck_node_t *a, deck_node_t *b)
{
	int aval, bval, i;

	char *arr[] = {"King", "Queen", "Jack", "10", "9",
		   "8", "7", "6", "5", "4", "3", "2", "Ace"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(a->card->value, arr[i]) == 0)
		{
			aval = i;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		if (strcmp(b->card->value, arr[i]) == 0)
		{
			bval = i;
			break;
		}
	}
	if (a->card->kind == b->card->kind)
		return (aval > bval);
	return (a->card->kind < b->card->kind);
}

/**
 * insertion_sort_list - sorts a doubly linked list of interger
 * using the Insertion sort
 * @list: pointer to the pointer that points to list.
 *
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *tmp, *curr, *i;

	if (!list || !*list)
		return;
	i = *list;
	while (i)
	{
		curr = i;
		while (curr && curr->prev)
		{
			tmp = curr;
			if (compare(tmp, tmp->prev))
				swap_l(tmp->prev, tmp, list);
			else
				curr = curr->prev;
		}
		i = i->next;
	}
}


/**
 * sort_deck -  sorts a deck of cards.
 * @deck: pointer to the pointer that pointer to deck.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}
