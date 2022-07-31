#include "deck.h"

/**
*swap - swaps 2 nodes in a doubly-linked list
*@a: address of first node
*@b: address of second node
*
*Return: void
*/
void swap(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (less_than(j->prev->card, j->card))
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
			}
			else
				j = j->prev;
		}

	}
}

/**
* sort_deck - sorts the deck by a given sort function
* @deck: address to pointer of head
*
*/
void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}

/**
* less_than - determines comparison order between two cards
* @a: pointer of first card
* @b: pointer of second card
*
* Return: true if a > b
*/
int less_than(const card_t *a, const card_t *b)
{
	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10", "9", "8",
		"7", "6", "5", "4", "3", "2", "Ace"};
	int val_a = 0, val_b = 0, i = 0;

	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)a->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_a = i;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)b->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_b = i;
			break;
		}
	}
	if (a->kind == b->kind)
		return (val_a < val_b);
	return (a->kind > b->kind);

}
