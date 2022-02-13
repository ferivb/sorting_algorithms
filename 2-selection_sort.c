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
 * selection_sort - Sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 *
 * @array: Array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, holder;
	int min, temp;

	while (unsorted(array, size) && size > 1)
	{
		for (; i < (size - 1); i++)
		{
			j = i;
			min = array[i];
			for (; j < size; j++)
			{
				if (array[j] < min)
				{
					min = array[j];
					holder = j;
				}
			}
			temp = array[i];
			array[i] = min;
			array[holder] = temp;
			print_array((const int *)array, size);
		}
	}
}
