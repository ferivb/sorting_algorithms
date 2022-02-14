#include "sort.h"

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 */
void swap(int *x, int *y)
{
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *array, int low, int high)
{
	int i, j, pivot_value = 0;

	pivot_value = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return (i);
}

/**
 * @brief 
 * 
 * @param array 
 * @param low 
 * @param high 
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		print_array((const int *)array, size);
		quicksort_recursion(array, low, (pivot_index - 1), size);
		quicksort_recursion(array, (pivot_index + 1), high, size);
	}
}

/**
 * @brief 
 * 
 * @param array 
 * @param size 
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	
	quicksort_recursion(array, 0, (size - 1), size);
}