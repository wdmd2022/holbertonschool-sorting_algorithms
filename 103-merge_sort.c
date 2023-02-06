#include "sort.h"

/**
 * merge_sort - sorts an array using merge sort
 * @array: pointer to an array of integers to sort
 * @size: size of the array to sort
 */
void merge_sort(int *array, size_t size)
{
	int *temporary_array = malloc(sizeof(array[0]) * size);

	arraymeagain(array, 0, size, temporary_array);
	splitit(temporary_array, 0, size, array);
	free(temporary_array);
}

/**
 * arraymeagain - copies input array
 * @array: pointer to an array of integers
 * @dest: pointer to destination array
 * @begin: index of array at start
 * @end: index of array at end
 */
void arraymeagain(int *array, int begin, int end, int *dest)
{
	int i;

	for (i = begin; i < end; i++)
	{
		dest[i] = array[i];
	}
}

/**
 * splitit - recursively splits an array
 * @array: pointer to array
 * @brray: pointer to second array, the temp one
 * @begin: index of array where want to start
 * @end: index of array where want to end
 */
void splitit(int *brray, int begin, int end, int *array)
{
	int midpoint;

	midpoint = ((begin + end) / 2);
	if (end - begin <= 1)
	{
		return;
	}
	splitit(array, begin, midpoint, brray);
	splitit(array, midpoint, end, brray);
	combinearray(brray, begin, midpoint, end, array);
}

/**
 * arrayprinter - prints an array
 * @array: pointer to the array we want to print
 * @begin: index point for starting
 * @end: index point for ending
 */
void arrayprinter(int *array, int begin, int end)
{
	int index;

	for (index = begin; index < end; index++)
	{
		printf("%d", array[index]);
		if ((index + 1) < end)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}
}

/**
 * combinearray - combines two sub-arrays
 * @array: pointer to array of integers
 * @brray: pointer to temp array of integers
 * @start: index of array to begin
 * @midpoint: midpoint index of array
 * @end: index of array at end
 */
void combinearray(int *array, int start, int midpoint, int end, int *brray)
{
	int s, m, e;

	s = start;
	m = midpoint;
	for (e = start; e < end; e++)
	{
		if (s < midpoint && (m >= end || array[s] <= array[m]))
		{
			brray[e] = array[s];
			s++;
		}
		else
		{
			brray[e] = array[m];
			m++;
		}
	}
	printf("Merging...\n[left]: ");
	arrayprinter(array, start, midpoint);
	printf("[right]: ");
	arrayprinter(array, midpoint, end);
	printf("[Done]: ");
	arrayprinter(brray, start, end);
}
