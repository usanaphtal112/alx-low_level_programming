#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index
 * @head: Double pointer to the head of the list.
 * @index: Index of the node that should be deleted (starting at 0).
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (*head == NULL) /* Check if the list is empty.*/
		return (-1);

	if (index == 0) /* Deleting the head node.*/
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;

	while (current != NULL)
	{
		if (count == index - 1) /* Node before the one to be deleted.*/
		{
			if (current->next == NULL) /* Index is beyond the end of the list.*/
				return (-1);

			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}

		current = current->next;
		count++;
	}

	return (-1);
}
