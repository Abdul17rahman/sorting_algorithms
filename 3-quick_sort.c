#include "sort.h"

/**
* swap - swaps elements
* @a: element a
* @b: element b
*
* description: Prints a comma seperated list
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* partition - Partitions the array
* @array: Array to partition
* @lb: Lower bound/first element
* @size: Upper bound/size
*
* description: Sorts the left and right of the pivot
* Return: the last element
*/
int partition(int *array, size_t lb, size_t size)
{
	int pvt = array[lb];
	size_t start = lb;
	size_t end = size;

	while (start < end)
	{
		while (array[start] <= pvt)
			start++;
		while (array[end] > pvt)
			end--;
		if (start < end)
		{
			swap(&array[start], &array[end]);
		}
	}
	swap(&array[lb], &array[end]);
	return (end);
}

/**
 * quick_sort - Sorts elements thru partition
 * @array: array to sort
 * @size: size of the array
 *
 * description: Through recursion, it partitions and sort
 */
void quick_sort(int *array, size_t size)
{
	size_t loc;

	if (size <= 1)
		return;
	loc = partition(array, 0, size - 1);
	quick_sort(array, loc);
	quick_sort(array + loc + 1, size - loc - 1);
}
