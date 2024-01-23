#include "sort.h"

/**
 * QUICK_SORT - SORTS AN ARRAY WITH THE QUICKSORT ALGORITHM
 * @array: ARRAY OF INTS TO SORT
 * @size: SIZE OF THE ARRAY
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	Quick_Recursion(array, 0, (int)size - 1, size);
}

/**
 * QUICK_RECURSION - HELPER FUNCTION FOR QUICKSORT
 * @array: ARRAY TO SORT
 * @left: INDEX OF THE left ELEMENT
 * @right: INDEX OF THE RIGHT ELEMENT
 * @size: SIZE OF THE ARRAY
 */

void Quick_Recursion(int *array, int left, int right, size_t size)
{
	int PIV;

	if (left < right)
	{
		PIV = Partition(array, left, right, size);
		Quick_Recursion(array, left, PIV - 1, size);
		Quick_Recursion(array, PIV + 1, right, size);
	}
}

/**
 * PARTITION - GIVES A PIVOT INDEX FOR QUICKSORT
 * BY UTILIZING THE LOMUTO PARTITION SCHEME
 * @array: ARRAY TO FIND THE PIVOT IN
 * @left: INDEX OF THE left ELEMENT
 * @right: INDEX OF THE RIGHT ELEMENT
 * @size: SIZE OF THE ARRAY
 *
 * RETURN: THE INDEX OF THE PIVOT ELEMENT
 */
int Partition(int *array, int left, int right, size_t size)
{
	int temp, a;
	int b;

	a = left - 1;

	for (b = left; b < right; b++)
	{
		if (array[b] < array[right])
		{
			a++;
			if (a != b)
			{
				temp = array[a];
				array[a] = array[b];
				array[b] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[a + 1])
	{
		temp = array[a + 1];
		array[a + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (a + 1);
}
