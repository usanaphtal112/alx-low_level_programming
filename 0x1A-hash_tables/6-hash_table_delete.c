#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its contents.
 *
 * Description: This function deallocates the memory used by the given hash
 * all key-value pairs stored in it. It frees the memory occupied
 * in the hash table and the array itself. After calling this function,
 * the hash table should not be accessed.
 *
 * @ht: A pointer to the hash table to be deleted.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
