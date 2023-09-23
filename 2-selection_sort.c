#include "sort.h"

/**
 * selection_sort - This sorts the an array of given
 * interger in a given order.
 * @array: This is an array of integers to be returned.
 * @size: This returns the  size of the array.
 * Description: This prints the an array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, idx = 0;
	int tmp = 0;

	if (size <= 1)
		return;
	while (i < size - 1)
	{
		idx = i;
		tmp = array[i];
		j = i + 1;
		while (j < size)
		{
			if (array[j] < tmp)
            {
                tmp = array[j];
                idx = j;
            }
			j++;
		}
		if (idx != i)
		{
			array[idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
