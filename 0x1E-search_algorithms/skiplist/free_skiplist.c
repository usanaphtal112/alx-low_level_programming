#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_skiplist - Frees a skip list
 * @list: Pointer to the head of the skip list to be freed
 */

void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_skiplist(node);
	}
}
