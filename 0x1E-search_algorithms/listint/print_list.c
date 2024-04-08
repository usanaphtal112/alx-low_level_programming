#include <stdio.h>
#include "../search_algos.h"

/**
 * free_list - Frees a linked list
 * @list: Pointer to the head of the list to be freed
 */

void print_list(const listint_t *list)
{
	printf("List :\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}
