#include "sort.h"

/**
 * counting_sort - function description
 * @array: parameter description
 * @size: parameter description
 */
void counting_sort(int *array, size_t size)
{
	int *other = NULL, max = 0, acc = 0, j = 0;
	size_t i = 0;

	if (size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	other = malloc((max + 1) * sizeof(int));

	if (!other)
		return;
	for (i = 0; i < size; i++)
		other[array[i]] = other[array[i]] + 1;

	acc = 0;
	for (i = 0; i < (size_t)(max + 1); i++)
	{
		acc = acc + other[i];
		other[i] = acc;
	}
	print_array(other, max + 1);

	for (i = 0; i < (size_t)(max + 1); i++)
	{
		while (j < other[i])
		{
			array[j] = i;
			j++;
		}
	}
	free(other);
}
