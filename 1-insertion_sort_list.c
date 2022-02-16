#include "sort.h"

/**
 * insertion_sort_list - Sorts a DLL
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (list)
	{
		if (current->n > current->next->n)
		{
			current = current->next;
			while (current->prev != NULL)
			{
				if (current->n < current->prev->n)
				{
					temp = current->next;
					current->next = current->prev;
					current->prev = current->prev->prev;
					if (current->prev != NULL)
						current->prev->next = current;
					else
						*list = current;
					current->next->prev = current;
					if (temp != NULL)
					{
						current->next->next = temp;
						temp->prev = current->next;
					}
					else
						current->next->next = NULL;
					print_list(*list);
				}
				else
					current = current->prev;
			}
		}
		current = current->next;
		if (current->next == NULL)
			return;
	}
}
