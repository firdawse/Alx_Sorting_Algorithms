#include "sort.h"

void swap_ints(int *c, int *d);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - This swaps two integers in an array present.
 * @c: This is the first integer to be swapped.
 * @d: This is the  second integer to be swapped.
 */
void swap_ints(int *c, int *d)
{
	int temp;

	temp = *c;
	*c = *d;
	*d = temp;
}

/**
 * max_heapify - This turns a binary tree into a complete binary heap.
 * @array: This is an array of integers representing a binary tree.
 * @size: This is the size of the array/tree.
 * @base: This is an index of the base row of the tree.
 * @root: This is the root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, lrge;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	lrge = root;

	if (lft < base && array[lft] > array[lrge])
		lrge = lft;
	if (rght < base && array[rght] > array[lrge])
		lrge = rght;

	if (lrge != root)
	{
		swap_ints(array + root, array + lrge);
		print_array(array, size);
		max_heapify(array, size, base, lrge);
	}
}

/**
 * heap_sort - This implement the sorting algoritms using heap sort
 * algorithms.
 * @array: This is an array of integers.
 * @size: This is the  size of an array.
 * Description: This implement the shift down alogithms
 * andd prints the array after swap.
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		max_heapify(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_ints(array, array + k);
		print_array(array, size);
		max_heapify(array, size, k, 0);
	}
}
