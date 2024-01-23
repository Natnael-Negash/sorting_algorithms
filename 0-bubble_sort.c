#include "sort.h"
#include <stdio.h>

/**
 * BUBBLE_SORT - SORTS AN ARRAY IN ASCENDING ORDER
 * @array: ARRAY OF INTS TO SORT
 * @size: SIZE OF THE ARRAY
 */

void Bubble_sort(int *array, size_t size)
{
	unsigned int a, b;
	int tmp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
