#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
*siftdown - siftdown implementation
*
*@array: array to be sorted
*@start: start of array
*@end: end of array
*@size: size of array
*
*/
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, _swap, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_swap = root;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end &&
			array[_swap] < array[child + 1])
			_swap = child + 1;
		if (_swap == root)
			return;
		swap(array, size, &array[root], &array[_swap]);
		root = _swap;
	}
}

/**
*heapify - makes heap in-place
*
*@array: array to be sorted
*@size: size of array
*
*/
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		siftdown(array, start, size - 1, size);
		start--;
	}
}
/**
*heap_sort - heap sort algorithm
*
*@array: array to sort
*@size: size of array
*
*/
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		siftdown(array, 0, end, size);
	}
}
