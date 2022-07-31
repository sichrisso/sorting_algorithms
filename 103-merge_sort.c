#include "sort.h"

/**
 * merge_compare - compares merges
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{

			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - sorts top-down recursively
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, mid, array);
	merge_sort_top_down(new, mid, stop, array);
	merge_compare(new, start, stop, array);
}


/**
 * merge_sort - sorts by merge sort algorithm
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;


	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	merge_sort_top_down(array, 0, size, new);
	free(new);
}
