#include "sort.h"

/**
 * insertion_sort_list - sorting using insertion algorithm
 * @list: The list.
 * Description: The list is sorted by inserting the element
 *    to its expected position. Each element is checked with
 *   respect to the previous sorted list(to the left) and swap
 *   if it is less than the previous element.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head, *temp, *prev, *holder;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = head = *list;
	current = current->next;

	while (current != NULL)
	{
		while (current->prev != NULL)
		{
			prev = current->prev;
			holder = prev;
			if (prev->n > current->n)
			{
				temp = prev->prev;
				if (temp)
				{
					temp->next = current;
				}
				current->prev = temp;
				prev->prev = current;
				prev->next = current->next;
				current->next = prev;
				if (prev->next != NULL)
					prev->next->prev = prev;
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			}
			current = holder;
		}
		current = head->next;
		head = current;
	}
}
