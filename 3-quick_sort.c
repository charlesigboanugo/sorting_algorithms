#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 * @size: The size of the array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp = array[i];

	if (i != j)
	{
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partition the array using Lomuto scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], j;
	int i = low - 1, all_same = 1;

	for (j = low; j < high; j++)
	{
		if (array[j] != pivot)
			all_same = 0;
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (all_same ? -1 : i + 1);
}

/**
 * quick_sort_rec - Recursively sort the array
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);

		if (p != -1)
		{
			quick_sort_rec(array, low, p - 1, size);
			quick_sort_rec(array, p + 1, high, size);
		}
	}
}

/**
 * quick_sort - Public function to sort the array
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_rec(array, 0, (int)size - 1, size);
}

