#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Helper function to merge the sequences in bitonic sort
 * @array: The array to be sorted
 * @low: The starting index of the sequence
 * @count: The number of elements in the sequence
 * @direction: 1 for ascending, 0 for descending
 * @size: Total size of the array (for display purposes)
 */
void bitonic_merge(int *array, int low, int count, int direction, size_t size)
{
	int i, temp, k = count / 2;

	if (count > 1)
	{
		for (i = low; i < low + k; i++)
		{
			if ((direction == 1 && array[i] > array[i + k]) ||
				(direction == 0 && array[i] < array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, size);
			}
		}
		bitonic_merge(array, low, k, direction, size);
		bitonic_merge(array, low + k, k, direction, size);
	}
}

/**
 * bitonic_recursion - Recursively creates bitonic sequences and sorts them
 * @array: The array to be sorted
 * @low: The starting index of the sequence
 * @count: The number of elements in the sequence
 * @direc: 1 for ascending, 0 for descending
 * @size: Total size of the array (for display purposes)
 */
void bitonic_recursion(int *array, int low, int count, int direc, size_t size)
{
	int k = count / 2;
	const char *dirc = direc ? "UP" : "DOWN";

	if (count > 1)
	{
		printf("Merging [%d/%lu] (%s):\n", count, size, dirc);
		print_array(&array[low], count);

		bitonic_recursion(array, low, k, 1, size);
		bitonic_recursion(array, low + k, k, 0, size);
		bitonic_merge(array, low, count, direc, size);

		printf("Result [%d/%lu] (%s):\n", count, size, dirc);
		print_array(&array[low], count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using bitonic
 * sort
 * @array: The array to be sorted
 * @size: The size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_recursion(array, 0, size, 1, size);
}

