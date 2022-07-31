/*
Instead of this:
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
Try this:
	size_t n = 101;
    array = rand_array(n, 1000);
*/

#include <time.h>

/**
 * rand_array - generates random int array
 *
 * @len: the length of the array
 * @max: the max size of each integer
 * 
 * Return: the generated int array
 */
int *rand_array(int len, int max)
{
	int *arr;

	arr = calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	if (!max)
		max = RAND_MAX;
	srand(time(NULL));
	while (len--)
		arr[len] = rand() % max;
	return (arr);
}
