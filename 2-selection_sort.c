#include "sort.h"

/**
 * SELECTION_SORT - SORTS AN ARRAY FOLLOWING THE SELECTION SORT ALGORITHM
 * @array: ARRAY TO SORT
 * @size: SIZE OF THE ARRAY;
 */

void select_sort(int *array, size_t size)
{
	unsigned int a, b, mini;

	register int temp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		mini = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[mini])
				mini = b;
		}
		temp = array[a];
		array[a] = array[mini];
		array[mini] = temp;
		if (a != mini)
			print_array(array, size);
	}
}

