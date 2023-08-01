#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Double pointer to the head of the list.
 * @n: Integer value for the new node.
 * Return: The address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *last = *head;

	if (new_node == NULL) /* Check if memory allocation failed.*/
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL) /* If the list is empty, make the new node the head.*/
	{
		*head = new_node;
	}
	else
	{
		/* Traverse the list to find the last node.*/
		while (last->next != NULL)
			last = last->next;

		/* Add the new node after the last node.*/
		last->next = new_node;
	}

	return (new_node);
}
