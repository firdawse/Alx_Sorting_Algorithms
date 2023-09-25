#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr -This sorts a subarray of integers.
 * @subarr:This is  a subarray of an array of integers to sort.
 * @buff: This is a buffer to store the sorted subarray.
 * @front: This is the front index of the array.
 * @mid: This is the middle index of the array.
 * @back: This is the back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t k, jj, i = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (k = front, jj = mid; k < mid && jj < back; i++)
		buff[i] = (subarr[k] < subarr[jj]) ? subarr[k++] : subarr[jj++];
	for (; k < mid; k++)
		buff[i++] = subarr[k];
	for (; jj < back; jj++)
		buff[i++] = subarr[jj];
	for (k = front, k = 0; k < back; k++)
		subarr[k] = buff[i++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - This implements the sorting algorithms using
 * merge sort algorithms.
 * @subarr: This is the subarray to be returned
 * @buff: This is a buffer to store the sorted result
 * @front: This is the front index of the subarray.
 * @back: This is the back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, middle);
		merge_sort_recursive(subarr, buff, middle, back);
		merge_subarr(subarr, buff, front, middle, back);
	}
}

/**
 * merge_sort - This sorts an array of an interger using
 * merge sort algorithms.
 * @array: This is an array of integers.
 * @size: This is a size of the array.
 * Description: This is the implementation the top-down merge sort
 *  algorithm given.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
