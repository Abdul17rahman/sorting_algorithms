#include "sort.h"
/**
 * prints - This  will print left, right, and merged halves
 * @arr: this is original or tmp array
 * @side: side or merged halves of the array
 * @start: starting indice
 * @end: ending indice
 */
void prints(int *arr, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}

}
/**
 * recur_merge - uses recursive splits and merges halves
 * @array: original array
 * @sortedArr: tmp array to hold sorted elements
 * @l: starting indice
 * @r: ending indice
 */
void recur_merge(int *array, int *sortedArr, size_t l, size_t r)
{
	size_t i, l_half, r_half;
	size_t mid = (l + r) / 2;

	if (r - l <= 1)
		return;

	recur_merge(array, sortedArr, l, mid);
	recur_merge(array, sortedArr, mid, r);
	printf("Merging...\n");
	prints(array, "left", l, mid);
	prints(array, "right", mid, r);
	l_half = l;
	r_half = mid;
	for (i = l; i < r; i++)
	{
		if ((l_half < mid) &&
		    ((r_half == r) || (array[l_half] < array[r_half])))
		{
			sortedArr[i] = array[l_half];
			l_half++;
		}
		else
		{
			sortedArr[i] = array[r_half];
			r_half++;
		}
	}
	prints(sortedArr, "Done", l, r);
	for (i = l; i < r; i++)
		array[i] = sortedArr[i];
}
/**
 * merge_sort - sorts  the array  by merging
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *sortedArr;

	if (!(array) || size < 2)
		return;
	sortedArr = malloc(sizeof(int) * size);
	if (!(sortedArr))
		return;
	recur_merge(array, sortedArr, 0, size);
	free(sortedArr);
}
