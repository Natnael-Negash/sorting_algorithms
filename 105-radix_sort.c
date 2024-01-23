#include "sort.h"

/**
 * RADIX_SORT - SORTS AN ARRAY FOLLOWING THE RADIX SORT ALGORITHM
 * @array: array of ints to sort
 * @size: size of the array
 */
void Radix_Sort(int *array, size_t size)
{
	int max;
	size_t a, lsd;

	if (!array || size < 2)
		return;

	max = 0;
	for (a = 0; a < size; a++)
		if (array[a] > max)
			max = array[a];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * COUNT_SORT_LSD - COUNT SORT WITH LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *out_arr, a, b;
	size_t c, d;

	out_arr = malloc(sizeof(int) * size);

	for (c = 0; c < size; c++)
		count_arr[(array[c] / lsd) % 10]++;
	for (a = 1; a < 10; a++)
		count_arr[a] += count_arr[a - 1];

	for (b = size - 1; b >= 0; b--)
	{
		out_arr[count_arr[(array[b] / lsd) % 10] - 1] = array[b];
		count_arr[(array[b] / lsd) % 10]--;
	}

	for (d = 0; d < size; d++)
		array[d] = out_arr[d];

	free(out_arr);
}
