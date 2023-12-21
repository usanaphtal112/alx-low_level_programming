#include "hash_tables.h"
/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 *
 * Description: This function searches for the specified key in the given
 * hash table and returns the corresponding value if the key is found.
 * If the key is not present in the hash table, NULL is returned.
 *
 * @ht: A pointer to the hash table from which to retrieve the value.
 * @key: The key for which the associated value is to be retrieved.
 *
 * Return: Returns a pointer to the value associated with the key
 * or NULL if the key is not found or if ht or key is NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
