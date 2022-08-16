#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort algorithm
 * @array: array to be sorted
 * @size: size_t type, number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int index = 0;
	unsigned long int jindex;
	int tempeh;

	for (; index < size - 1; index++)
	{
		for (jindex = 0; jindex < size - index - 1; jindex++)
		{
			if (array[jindex] > array[jindex + 1])
			{
				tempeh = array[jindex];
				array[jindex] = array[jindex + 1];
				array[jindex + 1] = tempeh;
			}
		}
		print_array(array, size);
	}
}
