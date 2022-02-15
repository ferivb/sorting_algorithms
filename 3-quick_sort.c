#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @x: Integer to swap
 * @y: Integer to swap
 */
void swap(int *x, int *y)
{
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Splits the array using the lomuto scheme
 *
 * @array: Array to partition
 * @low: Start of the array
 * @high: End of the array
 * @size: Size of the array
 * Return: Pivot point of the array
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot_value = 0;

	pivot_value = array[high];
	i = (low - 1);

	for (j = low; j <= (high - 1); j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array((const int *)array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array((const int *)array, size);
	}

	return (i + 1);
}

/**
 * quicksort_recursion - Recursivelly sorts the array
 *
 * @array: Array to sort
 * @low: Beginning of the array
 * @high: End of the array
 * @size: Size of the array
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index = 0;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quicksort_recursion(array, low, (pivot_index - 1), size);
		quicksort_recursion(array, (pivot_index + 1), high, size);
	}
}

/**
 * quick_sort - Sorts an array using the lomuto scheme
 *
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}
