#include "sort.h"

/**
 * unsorted - Checks if the array is sorted
 *
 * @array: The array to check
 * @size: The size of the array
 * Return: 1 if unsorted, 0 if sorted
 */
int unsorted(int *array, size_t size)
{
	size_t i = 0;

	for (; i < (size - 1); i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}


/**
 * bubble_sort - Sorts 2 positions each iteration
 *
 * @array: Array to sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t j = 0;

	while (unsorted(array, size) && size > 1)
	{
		j = 0;
		for (; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array((const int *)array, size);
			}
		}
	}
	return;
}
