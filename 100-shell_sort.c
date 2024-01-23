#include "sort.h"

/**
* sHELL_SORT - FUNCTION SORTS AN ARRAY OF INTEGERS USING
* THE SHELL SORT ALGORITHM WITH KNUTH SEQUENCE
* @array: THE ARRAY OF INTEGERS
* @size: SIZE OF THE ARRAY
*
* return: NONE
*/
void Shell_Sort(int *array, size_t size)
{
	size_t gap = 0, b, a;
	int tmp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b >= gap && tmp <= array[b - gap]; b -= gap)
				array[b] = array[b - gap];
			array[b] = tmp;
		}
		print_array(array, size);
	}
}
