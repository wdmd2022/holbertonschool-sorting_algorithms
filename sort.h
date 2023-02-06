#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

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


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void switcheroo(listint_t **head, listint_t **first, listint_t **second);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lomutorules(int *array, size_t size, unsigned int low, unsigned int high);
void merge_sort(int *array, size_t size);
void arraymeagain(int *array, int begin, int end, int *dest);
void splitit(int *brray, int begin, int end, int *array);
void arrayprinter(int *array, int begin, int end);
void combinearray(int *array, int start, int midpoint, int end, int *brray);


#endif
