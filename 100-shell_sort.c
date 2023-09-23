#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i = 0, j = 0;
	int tmp = 0;

	if (size < 2)
		return;
	while (n < size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		j = n;
		while (j < size)
		{
			tmp = array[j];
			i = j;
			while (i > n - 1 && array[i - n] >= tmp)
			{
				array[i] = array[i - n];
				i -= n;
			}
			array[i] = tmp;
			j++;
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
