#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @arr: array where swap would take place
 * @a: index of element to swap
 * @b: index of element to swap
 */
void swap(int *arr, size_t a, size_t b)
{
	int temp;

	temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapno = 1;

	for (i = 1; i < size && swapno; i++)
	{
		swapno = 0;
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
				swapno++;
			}
		}
	}
}
