#include "hash_tables.h"

/**
 * hash_table_print - Prints the content of a hash table.
 *
 * This function prints the key-value pairs stored in the given hash table.
 * The output is formatted as a JSON-like representation enclosed in curly
 * braces. If the hash table is empty, an empty set of curly braces is printed
 *
 * @param ht    A pointer to the hash table to be printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
