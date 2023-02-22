#include "sort.h"

/**
 * count_in_sort - sorts using counting sort (significant places)
 * @array: the array of ints which we wish to sort
 * @size: int, the size of the array
 * @place: int, to track digit location
 * @brray: the newly sorted array of ints
 */
void count_in_sort(int *array, int size, int place, int *brray)
{
	int i, count[10] = { 0 };

	for (i = 0; i < size; i++)
	{
		count[(array[i] / place) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		brray[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = brray[i];
	}
}

/**
 * radix_sort - uses LSD radix sort algorithm to sort an array of ints
 * @array: array of integers to sort
 * @size: size_t int, represents size of array
 */
void radix_sort(int *array, size_t size)
{
	int place;
	int max;
	int ll_cool_size;
	int i;
	int brray[1024];

	if (!array || size < 2)
	{
		return;
	}
	max = array[0];
	ll_cool_size = (int)size;
	for (i = 1; i < ll_cool_size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	for (place = 1; max / place > 0; place *= 10)
	{
		count_in_sort(array, ll_cool_size, place, brray);
		print_array(array, size);
	}
}
