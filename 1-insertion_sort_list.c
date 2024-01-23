#include "sort.h"

/**
 * LEN_LIST - RETURNS THE LENGTH OF A LINKED LIST
 * @h: POINTER TO THE LIST
 *
 * RETURN: LENGTH OF LIST
 */
int len_list(listint_t *h)
{
	int length = 0;

	while (h)
	{
		length++;
		h = h->next;
	}
	return (length);
}

/**
 * INSERTION_SORT_LIST - SORTS A LINKED LIST WITH THE INSERT SORT ALGORITHM
 * @list: DOUBLE POINTER TO THE LIST TO SORT
 */
void insert_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
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
				*list = three;
			two->prev = three;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
