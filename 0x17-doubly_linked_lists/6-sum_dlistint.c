#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all elements in a doubly linked list.
 *
 * @head: A pointer to the head of the doubly linked list.
 *
 * Return: The sum of all elements in the list. If the list is empty, return 0.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}
