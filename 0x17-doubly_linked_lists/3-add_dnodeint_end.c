#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 *
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node, or NULL if memory allocation
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = h;

	return (new);
}
