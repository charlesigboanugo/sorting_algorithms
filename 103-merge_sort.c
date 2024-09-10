#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two halves of an array in sorted order.
 * @array: The array containing two sorted halves to be merged.
 * @left: The leftmost index of the first half.
 * @right: The rightmost index of the second half.
 *
 * This function merges two sorted halves of the array `array` in-place.
 * It uses a temporary array `tmp` to store the merged result and then copies
 * the result back to the original array.
 */
void merge(int *array, size_t left, size_t right)
{
	size_t tmp_size = (right - left + 1);
	size_t half = tmp_size / 2, i = left, j = left + half, k;
	int *tmp;

	tmp = malloc(sizeof(int) * tmp_size);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	for (k = 0; i < left + half && j <= right; k++)
	{
		if (array[i] <= array[j])
		{
			tmp[k] = array[i];
			i++;
		}
		else
		{
			tmp[k] = array[j];
			j++;
		}
	}
	for (; i < left + half; i++, k++)
		tmp[k] = array[i];
	for (; j <= right; j++, k++)
		tmp[k] = array[j];
	printf("merging...\n");
	printf("[left]: ");
	for (i = left; i < left + half - 1; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);
	printf("[right]: ");
	for (; i <= right - 1; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);
	printf("[done]: ");
	for (i = 0; i < tmp_size - 1; i++)
		printf("%i, ", tmp[i]);
	printf("%i\n", array[i]);
	for (i = left; i <= right; i++)
		array[i] = tmp[i - left];
	free(tmp);
}

/**
 * merge_recursion - Recursively applies merge sort to the array.
 * @array: The array to be sorted.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 *
 * This function recursively divides the array size_to two halves and
 * calls the merge function to merge the sorted halves.
 */
void merge_recursion(int *array, size_t left, size_t right)
{
	size_t half = (right - left + 1) / 2;

	if (left < right)
	{
		merge_recursion(array, left, left + half - 1);
		merge_recursion(array, left + half, right);
		merge(array, left, right);
	}
}

/**
 * merge_sort - Public size_terface for merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * This function initiates the recursive merge sort.
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge_recursion(array, 0, size - 1);
}
