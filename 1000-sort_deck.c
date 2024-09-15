#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * compare_ckind - compares two nodes of a card deck by card kind
 *
 * @dknode1: first node to compare
 * @dknode2: second node
 *
 * Return: 1 if dknode1 is greather than dknode2 else -1
 */
int compare_ckind(const void *dknode1, const void *dknode2)
{
	deck_node_t *dk1 = *(deck_node_t **) dknode1;
	deck_node_t *dk2 = *(deck_node_t **) dknode2;

	return (dk1->card->kind > dk2->card->kind ? 1 : -1);
}

/**
 * compare_cval - compares two nodes of a card deck by card value
 *
 * @dknode1: first node to compare
 * @dknode2: second node
 *
 * Return: 1 if dknode1 is greather than dknode2 else -1
 */
int compare_cval(const void *dknode1, const void *dknode2)
{
	deck_node_t *dk1 = *(deck_node_t **) dknode1;
	deck_node_t *dk2 = *(deck_node_t **) dknode2;
	int val1 = dk1->card->value[0];
	int val2 = dk2->card->value[0];

	switch (val1)
	{
		case 'A':
			val1 = 49;
			break;
		case 'J':
			val1 = 59;
			break;
		case 'Q':
			val1 = 60;
			break;
		case 'K':
			val1 = 61;
			break;
	}
	switch (val2)
	{
		case 'A':
			val2 = 49;
			break;
		case 'J':
			val2 = 59;
			break;
		case 'Q':
			val2 = 60;
			break;
		case 'K':
			val2 = 61;
			break;
	}
	if (!strcmp(dk1->card->value, "10"))
		val1 = 58;
	if (!strcmp(dk2->card->value, "10"))
		val2 = 58;
	return (val1 > val2 ? 1 : -1);
}

/**
 * sort_deck - sorts a deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t *arr[52];
	deck_node_t *dkptr;

	dkptr = *deck;
	for (i = 0; i < 52 && dkptr; dkptr = dkptr->next, i++)
		arr[i] = dkptr;

	qsort(arr, 52, sizeof(deck_node_t *), compare_ckind);

	for (i = 0; i < 52; i += 13)
		qsort(arr + i, 13, sizeof(deck_node_t *), compare_cval);

	dkptr = arr[0];
	dkptr->prev = NULL;
	for (i = 0; i < 51; i++)
	{
		dkptr->next = arr[i + 1];
		if (i > 1)
			dkptr->prev = arr[i - 1];
		dkptr = dkptr->next;
	}
	dkptr->next = NULL;
	*deck = arr[0];
}
