#include "sort.h"

/**
 * partition - This an array partition
 * @array: This is an array to be sorted
 * @first: The first position of the partition.
 * @last: The last position of the partition
 * @size: An array size to be returned.
 * Return: This is the int pivoted index to be returned.
 */
int partition(int *array, int first, int last, size_t size)
{
	int k = first - 1, a, jj;

	for (jj = first; jj <= last - 1; jj++)
	{
		if (array[jj] < array[last])
		{
			k++;
			if (k < jj)
			{
				a = array[k];
				array[k] = array[jj];
				array[jj] = a;
				print_array(array, size);
			}
		}
	}
	if (array[k + 1] > array[last])
	{
		a = array[k + 1];
		array[k + 1] = array[last];
		array[last] = a;
		print_array(array, size);
	}

	return (k + 1);
}

/**
 * qs - This sorts an array recursively
 * @array: This an array to be sorted.
 * @first: This is the first position
 * @last: This is the last position
 * @size: This is an array size
 */
void qs(int *array, int first, int last, size_t size)
{
	int pi;

	if (first < last)
	{
		pi = partition(array, first, last, size);
		qs(array, first, pi - 1, size);
		qs(array, pi + 1, last, size);
	}
}

/**
 * quick_sort - This sorts an array of interger using quick
 * sort algorithms.
 * @array: This is an array to be sorted
 * @size: An array size to be returned.
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
