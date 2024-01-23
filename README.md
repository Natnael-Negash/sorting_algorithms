# Sorting algorithms & Big O Notation

## Description

> A sorting algorithm is an algorithm made up of a series of instructions that takes a data structure as input, performs specified operations on the data structure, sometimes and outputs a sorted permutation of the data structure. Sorting algorithms are often taught early in computer science classes as they provide a straightforward way to introduce other key computer science topics like Big-O notation, divide-and-conquer methods, and data structures such as binary trees, and heaps. There are many factors to consider when choosing a       sorting algorithm to use.


> For example, a sorted array is an array that is in a particular order. For example, `[a,b,c,d]` is sorted alphabetically, `[1,2,3,4,5]` is a list of integers sorted in ascending order, and [5,4,3,2,1]` is a list of integers sorted in descending order.

## Resources

Read or watch:

- [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Time complexity](https://en.wikipedia.org/wiki/Time_complexity)
- [Simple explanation of Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation)
- [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
- [15 sorting algorithms in 6 minutes (WARNING: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)](https://www.youtube.com/watch?v=kPRA0W1kECg)
- [CS50 Algorithms explanation in detail by David Malan](https://cs50.harvard.edu/x/2023/notes/3/)
- [All about sorting algorithms - Geeks for Geeks resource](https://www.geeksforgeeks.org/sorting-algorithms/)

### Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General

- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

### Requirements
### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- No more than 5 functions per file
- The prototypes of all your functions should be included in your header file called `sort.h`
- Don’t forget to push your header file
- All your header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2.

### For this project make use of the following print_array, and print_list functions that are included in `sort.h`:

```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

```
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

```


Please use the following data structure for doubly linked list:
```

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
```

**1000-sort_deck.c**

