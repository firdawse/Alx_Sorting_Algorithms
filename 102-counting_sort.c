#include "sort.h"

/**
 * get_max - This gets the maximum value in an array of integers
 * given.
 * @array: This is an array of integers.
 * @size: This is the size of the integer to be returned.
 * Return: This is the  maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int mx, k;

	for (mx = array[0], k = 1; k < size; k++)
	{
		if (array[k] > mx)
			mx = array[k];
	}

	return (mx);
}

/**
 * counting_sort - This Sorts the given algorithms in using
 * counting method.
 * @array: This is an array of an integers.
 * @size: This is a size of the array.
 * Description: This prints the counting array after putting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *srted, mx, k;

	if (array == NULL || size < 2)
		return;

	srted = malloc(sizeof(int) * size);
	if (srted == NULL)
		return;
	mx = get_max(array, size);
	counter = malloc(sizeof(int) * (mx + 1));
	if (counter == NULL)
	{
		free(srted);
		return;
	}

	for (k = 0; k < (mx + 1); k++)
		counter[k] = 0;
	for (k = 0; k < (int)size; k++)
		counter[array[k]] += 1;
	for (k = 0; k < (mx + 1); k++)
		counter[k] += counter[k - 1];
	print_array(counter, mx + 1);

	for (k = 0; k < (int)size; k++)
	{
		srted[counter[array[k]] - 1] = array[k];
		counter[array[k]] -= 1;
	}

	for (k = 0; k < (int)size; k++)
		array[k] = srted[k];

	free(srted);
	free(counter);
}
