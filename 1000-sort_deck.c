#include "deck.h"

/**
 * SORT_DECK - SORTS A DECK OF CARD
 * @deck: doubly linked list to sort
 */
void Sort_Deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			curr = *deck;
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * CARD_VALUE - RETURNS THE VALUE OF A CARD
 * @node: card in a deck
 *
 * Return: value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int a, kind_val = 0;

	for (a = 1; a <= 13; a++)
	{
		if (!_strcmp(node->card->value, val[a - 1]))
			kind_val = a;
	}

	for (a = 1; a <= 4; a++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[a - 1]))
			kind_val = kind_val + (13 * a);
	}

	return (kind_val);
}

/**
 * _STRCMP - COMPARES TWO STRINGS
 * @s1: FIRST STRING TO COMPARE
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * LIST_LEN_DECK - FUNCTION RETURNS LENGTH OF LIST
 * @list: head of list
 *
 * Return: length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
