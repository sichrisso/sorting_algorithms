#include "sort.h"

void bitonic(int *array, size_t size, size_t p, size_t q)
{
	size_t d = 1UL << (p-q), i;

	for(i = 0; i < size; i++)
	{
		size_t up = ((i >> p) & 2) == 0;

		if ((i & d) == 0 && (array[i] > array[i | d]) == up) {
			int t = array[i];
			array[i] = array[i | d];
			array[i | d] = t;
			printf("Swapped: [%d] [%d]\n", array[i | d], array[i]);
		}
	}
}

void bitonic_sort(int *array, size_t size)
{
	size_t logn = 1, i, j;

	if (!array || size < 2)
		return;

	while (size >> (logn + 1))
		logn++;

	for (i = 0; i < logn; i++)
		for (j = 0; j <= i; j++)
			bitonic(array, size, i, j);
}
