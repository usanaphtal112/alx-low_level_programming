#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
void shash_table_delete(shash_table_t *ht);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void shash_table_print(const shash_table_t *ht);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print_rev(const shash_table_t *ht);

/**
 * shash_table_delete - Deletes a sorted hash table and its contents.
 *
 * This function deallocates the memory used
 * by the given sorted hash table,
 * including all key-value pairs stored in it.
 * It frees the memory occupied by
 * each node in the hash table and the array itself.
 * After calling this function, the sorted hash
 * table should not be accessed.
 *
 * @param ht    A pointer to the sorted hash table to be deleted.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}

/**
 * shash_table_create - Creates a sorted hash table.
 *
 * This function allocates memory for a new sorted hash table and initializes
 * its components, including the array of pointers, head, and tail for sorted
 * access. The size parameter determines the initial size of the array.
 *
 * @param size  The initial size of the array in the sorted hash table.
 *
 * @return      A pointer to the created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_get - Retrieve the value associated
 * with a key in a sorted hash table.
 *
 * This function searches for the specified key in the
 * given sorted hash table and returns the corresponding
 * value if the key is found.
 * If the key is not present in the hash table, NULL is returned.
 *
 * @param ht    A pointer to the sorted hash table from which
 * @param key   The key for which the associated value is to be retrieved.
 *
 * @return      Returns a pointer to the value associated with the key
 *              the key is not found or if ht or key is NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_set - Adds or updates a key-value pair in a sorted hash table.
 *
 * This function sets a key-value pair in the given sorted hash table.
 * If the key already exists in the hash table, the
 * corresponding value is updated. If the key is not present,
 * a new entry is created for the key-value pair
 * and the sorted order is maintained based on the keys.
 *
 * @param ht    A pointer to the sorted hash table
 * where the key-value pair will be set.
 * @param key   The key to be added or updated in the sorted hash table.
 * @param value The value associated with the key to be set.
 *
 * @return      Returns 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_print - Prints the content of a sorted hash table.
 *
 * This function prints the key-value pairs stored in the given sorted
 * The output is formatted as a JSON-like representation enclosed
 * If the hash table is empty, an empty set of curly braces is printed.
 *
 * @param ht    A pointer to the sorted hash table to be printed.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the content of a sorted hash table.
 *
 * This function prints the key-value pairs stored in the given sorted.
 * in reverse order. The output is formatted as a JSON-like representation
 * in curly braces. If the hash table is empty, an empty set of curly braces.
 *
 * @param ht    A pointer to the sorted hash table to be printed in reverse.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}
