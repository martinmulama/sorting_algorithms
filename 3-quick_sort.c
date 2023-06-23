#include "sort.h"
#include <stdio.h>

/**
 * partition - partitions the array
 * @array: array to take in
 * @low: low index of array
 * @high: high index of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quickSort - quick sorts with recursion
 * @array: array to sort through
 * @low: low index of array or subarray
 * @high: high index of array or subarray
 * @size: size of full array
 */
void quickSort(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
