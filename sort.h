#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void Bubble_sort(int *array, size_t size);
int len_list(listint_t *h);
void insert_sort_list(listint_t **list);
void select_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void Quick_Recursion(int *array, int left, int right, size_t size);
int Partition(int *array, int left, int right, size_t size);
void Shell_Sort(int *array, size_t size);
void Switch_node(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void Merge_Recursion(int *arr, int *array, size_t left, size_t right);
void Merge_Subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right);
void heap_sort(int *array, size_t size);
void HEapify(int *array, size_t s, size_t root, size_t size);
void Radix_Sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void Quick_Sort_hore(int *array, size_t size);
void Bitonic_Sort(int *array, size_t size);
void Bitonic_Recursion(int *array, int l, int r, int direction, size_t size);
void Bitonic_Merge(int *array, int l, int r, int direction);

#endif
