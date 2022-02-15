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
	if (array[i +1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array((const int *)array, size);
	}

	return (i + 1);
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
	int pivot_index = 0;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
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
	if (size < 2 || array == NULL)
		return;
	
	quicksort_recursion(array, 0, size - 1, size);
}