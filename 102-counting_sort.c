#include "sort.h"

/**
 * COUNTING_SORT - SORTS AN ARRAY WITH THE COUNTING SORT ALGORITHM
 * @array: ARRAY TO SORT
 * @size: SIZE OF THE ARRAY
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max, num, b, a;
	size_t i, k, m, n;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_arr = malloc(sizeof(size_t) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	for (b = 0; b <= max; b++)
		count_arr[b] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_arr[num] += 1;
	}
	for (a = 1; a <= max; a++)
		count_arr[a] += count_arr[a - 1];
	print_array(count_arr, max + 1);
	for (m = 0; m < size; m++)
	{
		out_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(count_arr);
	free(out_arr);
}
