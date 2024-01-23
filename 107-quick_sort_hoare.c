#include "sort.h"

/**
 * QUICK_SORT_HOARE - SORTS AN ARRAY WITH THE QUICKSORT ALGORITHM
 * @array: array of ints to sort
 * @size: size of the array
 */
void Quick_Sort_hore(int *array, size_t size)
{
	if (size < 2)
		return;

	Quick_Recursion(array, 0, (int)size - 1, size);
}

/**
 * Quick_Recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void Quick_Recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = Partition(array, left, right, size);
		Quick_Recursion(array, left, piv - 1, size);
		Quick_Recursion(array, piv, right, size);
	}
}

/**
 * Partition - gives a piv index for Quicksort
 * @array: array to find the piv in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the piv element
 */
int Partition(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t a, b;

	a = left - 1;
	b = right + 1;
	while (1)
	{
		do {
			a++;
		} while (array[a] < pivot);
		do {
			b--;
		} while (array[b] > pivot);
		if (a >= b)
			return (a);
		if (a != b)
		{
			tmp = array[a];
			array[a] = array[b];
			array[b] = tmp;
			print_array(array, size);
		}
	}
	return (0);
}
