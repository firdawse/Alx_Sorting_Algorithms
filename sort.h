#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - This is a Doubly linked list node
 * @n: Integer stored in the node present
 * @prev: Pointer to the previous element of the lists
 * @next: Pointer to the next element of the lists
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
/*Sorting algorithms*/
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_ints(int *f, int *s);
void swap(listint_t **node, listint_t **list);
void insertion_sort_list(listint_t **list);

#endif
