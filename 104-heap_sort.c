#include "sort.h"

/**
 * HEAP_SORT - SORTS AN ARRAY FOLLOWING THE HEAP SORT ALGORITHM
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int a;
	int temp;

	if (size < 2)
		return;

	for (a = size / 2 - 1; a >= 0; a--)
		HEapify(array, size, (size_t)a, size);

	for (a = size - 1; a >= 0; a--)
	{
		temp = array[a];
		array[a] = array[0];
		array[0] = temp;
		if (a != 0)
			print_array(array, size);
		HEapify(array, (size_t)a, 0, size);
	}
}

/**
 * HEAPIFY - TURNS AN ARRAY IN A HEAP TREE
 * @array: array to turn into heap
 * @s: size of the subtree
 * @root: index of the subtree in the heap
 * @size: size of the whole array
 */
void HEapify(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int temp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		HEapify(array, s, max, size);
	}
}
