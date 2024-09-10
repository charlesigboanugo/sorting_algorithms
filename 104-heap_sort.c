#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 * @size: The size of the array (for printing after swap)
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int tmp;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;

		print_array(array, size);
	}
}

/**
 * sift_down - Repairs the heap whose root element is at index start,
 * assuming the heaps rooted at its children are valid.
 * @array: The array representing the heap
 * @start: The root of the heap to sift down
 * @end: The last index of the heap
 * @size: The size of the array (for printing)
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap_idx;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(array, root, swap_idx, size);
		root = swap_idx;
	}
}

/**
 * heapify - Builds the max heap by calling sift_down on all non-leaf nodes
 * @array: The array to heapify
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
	for (ssize_t start = (size - 2) / 2; start >= 0; start--)
	{
		sift_down(array, start, size - 1, size);
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	heapify(array, size);

	for (size_t end = size - 1; end > 0; end--)
	{
		swap(array, end, 0, size);
		sift_down(array, 0, end - 1, size);
	}
}

