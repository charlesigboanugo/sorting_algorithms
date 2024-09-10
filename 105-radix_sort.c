#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Get the maximum value in the array
 * @array: The array of integers
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Performs a counting sort based on a significant digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The significant digit (exponent of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}

