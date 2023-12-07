#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at
 *
 * @head: A pointer to the head of the doubly linked list.
 * @index: The index of the node to retrieve (starting from 0).
 *
 * Return: A pointer to the node at the specified index, or NULL if the index
 *         out of range or if the list is empty.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size;
	dlistint_t *tmp;

	size = 0;
	if (head == NULL)
	return (NULL);

	tmp = head;
	while (tmp)
	{
	if (index == size)
	return (tmp);
	size++;
	tmp = tmp->next;
	}
	return (NULL);
}
