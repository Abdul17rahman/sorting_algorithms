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
* selection_sort - Sorts elements of array
* @array: Array to sort
* @size: Size of an array
*
* description: selects the smallest element
*
* Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
