#include "sort.h"

/**
 * swap_ints - This swaps two integers in an array.
 * @f: The first integer to be swaped.
 * @s: The second integer to be swaped
 */
void swap_ints(int *f, int *s)
{
	int temp;

	temp = *f;
	*f = *s;
	*s = temp;
}

/**
 * selection_sort - This sorts the an array of given
 * interger in a given order.
 * @array: This is an array of integers.
 * @size: This returns the  size of the array.
 * Description: This prints the an array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mn;
	size_t k, jj;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		mn = array + k;
		for (jj = k + 1; jj < size; jj++)
			mn = (array[jj] < *mn) ? (array + jj) : mn;

		if ((array + k) != mn)
		{
			swap_ints(array + k, mn);
			print_array(array, size);
		}
	}
}
