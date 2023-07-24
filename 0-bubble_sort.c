#include "sort.h"

/**
* buble_sort - Sorts elements of array
* @array: Array to sort
* @size: Size of an array
*
* description: Bubles to the end
*
* Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, f = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				f = 1;
			}
		}
		if (f == 0)
			break;
	}
}
