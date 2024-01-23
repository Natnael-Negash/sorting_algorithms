#include "sort.h"

/**
 * BITONIC_SORT - SORTS AN ARRAY FOLLOWING THE BITONIC SORT ALGORITHM
 * @array: array of ints to sort
 * @size: size of the array
 */
void Bitonic_Sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	Bitonic_Recursion(array, 0, size - 1, 1, size);
}

/**
 * BITONIC_RECURSION - RECURSIVE FUNCTION FOR BITONIC SORT
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void Bitonic_Recursion(int *array, int l, int r, int direction, size_t size)
{
	int Step;

	if (r - l >= 1)
	{
		Step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		Bitonic_Recursion(array, l, Step, 1, size);
		Bitonic_Recursion(array, Step + 1, r, 0, size);
		Bitonic_Merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * BITONIC_MERGE - SORTS AND MERGES A SEQUENCE IN ASCENDING OR DESCENDING ORDER
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending or descending
 */
void Bitonic_Merge(int *array, int l, int r, int direction)
{
	int temp, a, Step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (a = l; a < l + mid; a++)
		{
			if (direction == (array[a] > array[a + mid]))
			{
				temp = array[a + mid];
				array[a + mid] = array[a];
				array[a] = temp;
			}
		}
		Bitonic_Merge(array, l, Step, direction);
		Bitonic_Merge(array, Step + 1, r, direction);
	}

}
