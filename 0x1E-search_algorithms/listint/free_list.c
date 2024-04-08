#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_list - Frees a linked list
 * @list: Pointer to the head of the list to be freed
 */

void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}
