#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order using the Bubble sort algorithm
 * 
 * @array: Array of data to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int tmp;
    int is_sorted;

    if (size <= 1 || array == NULL)
        return;

    for (i = 0; i < size - 1; i++)
    {
        is_sorted = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                print_array(array, size);
                is_sorted = 1;
            }
        }

        if (is_sorted == 0)
            break;
    }
}
