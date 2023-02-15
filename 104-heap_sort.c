#include "sort.h"

/**
 * swap - function to swap two integers using pointers
 * @n: pointer to integer one
 * @m: pointer to integer two
 */
void swap(int *n, int *m)
{
	int swappy = *n;

	*n = *m;
	*m = swappy;
}

/**
 * buildMaxHeap - creates a Max-heap data structure,
 * given a binary tree represented using an array, with
 * the subtree rooted with index of node i
 * @array: array that we wish to turn into Max-heap
 * @i: int, represents index location of root node
 * @sizey: int, size of array
 * @size: size_t, size of array
 */
void buildMaxHeap(int *array, int i, int sizey, size_t size)
{
	int largest, left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < sizey && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < sizey && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		buildMaxHeap(array, largest, sizey, size);
	}
}

/**
 * heap_sort - uses Heap sort algorithm on array of integers
 * @array: array of integers
 * @size: size_t type, size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, sizey;

	sizey = (int)size;

	for (i = sizey / 2 - 1; i >= 0; i--)
	{
		buildMaxHeap(array, i, sizey, size);
	}
	for (i = sizey - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
		{
			print_array(array, size);
		}
		buildMaxHeap(array, 0, i, size);
	}
}
