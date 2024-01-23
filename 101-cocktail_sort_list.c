#include "sort.h"

/**
 * LIST_LEN - FUNCTION RETURNS LENGTH OF LIST
 * @list: HEAD OF LIST
 *
 * Return: LENGTH
 */
size_t list_len(listint_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * SWITCH_NODES - FUNCTION SWAPS NODES AT POINTER P WITH THE FOLLOWING NODE
 * @list: HEAD OF LIST
 * @p: POINTER TO NODE
 */
void Switch_node(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 *  COCKTAIL_SORT_LIST - FUNCTION SORTS A DOUBLY LINKED LIST USING
 * THE COCKTAIL SORT ALGORITHM
 * @list: POINTER TO LIST
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sort = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!sort)
	{
		sort = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sort = 0;
				Switch_node(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sort)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sort = 0;
				p = p->prev;
				Switch_node(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
