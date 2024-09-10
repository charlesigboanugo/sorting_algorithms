#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	int temp;

	if (array[i] > array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		printf("Swapped %d and %d\n", array[i], array[j]);
	}
}

/**
 * bitonic_merge - Merge a bitonic sequence
 * @array: The array to sort
 * @low: The starting index of the sequence
 * @count: The number of elements to consider
 * @dir: The direction to sort (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t k, i;

	if (count < 2)
		return;

	k = count / 2;
	printf("Merging [%zu/%zu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");

	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
		{
			swap(array, i, i + k);
		}
	}
	print_array(array, low, count);

	bitonic_merge(array, low, k, dir);
	bitonic_merge(array, low + k, k, dir);
}

/**
 * bitonic_sort_rec - Recursively sort a bitonic sequence
 * @array: The array to sort
 * @low: The starting index of the sequence
 * @count: The number of elements to consider
 * @dir: The direction to sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count < 2)
		return;

	k = count / 2;
	bitonic_sort_rec(array, low, k, 1);
	bitonic_sort_rec(array, low + k, k, 0);
	bitonic_merge(array, low, count, dir);
}

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || (size & (size - 1)) != 0)
		return;

	bitonic_sort_rec(array, 0, size, 1);
	printf("\nSorted array:\n");
	print_array(array, 0, size);
}

