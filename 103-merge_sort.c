#include "sort.h"

/**
 * MERGE_SORT - SORTS AN ARRAY WITH THE MERGE SORT ALGORITHM
 * @array: ARRAY OF INTS TO SORT
 * @size: SIZE OF THE ARRAY
 */
void merge_sort(int *array, size_t size)
{
	int *arg;

	if (!array || size < 2)
		return;

	arg = malloc(sizeof(int) * size);

	Merge_Recursion(arg, array, 0, size);
	free(arg);
}

/**
 * mERGE_RECURSION - RECURSIVE FUNCTION THAT MERGE SORTS AN ARRAY
 * @arg: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void Merge_Recursion(int *arg, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		Merge_Recursion(arg, array, left, middle);
		Merge_Recursion(arg, array, middle, right);
		Merge_Subarray(arg, array, left, middle, right);
	}
}

/**
 * MERGE_SUBARRAY - MERGES SUBARRAYS
 * @arg: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void Merge_Subarray(int *arg, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t a, b, m = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (a = left, b = middle; a < middle && b < right; m++)
	{
		if (array[a] < array[b])
			arg[m] = array[a++];
		else
			arg[m] = array[b++];
	}

	while (a < middle)
		arg[m++] = array[a++];
	while (b < right)
		arg[m++] = array[b++];

	for (m = left, a = 0; m < right; m++)
		array[m] = arg[a++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
