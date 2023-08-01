#include "lists.h"

/**
 * find_loop - Detects the loop in a listint_t linked list.
 * @head: Pointer to the head of the list.
 * Return: A pointer to the node where the loop starts, or NULL if no loop.
 */

listint_t *find_loop(listint_t *head)
{
	listint_t *slow, *fast;

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (slow);
	}

	return (NULL);
}

/**
 * free_nodes_after_loop - Frees the nodes after the loop
 * @head: Pointer to the head of the list.
 * @loop_node: Pointer to the node where the loop starts.
 */

void free_nodes_after_loop(listint_t *head, listint_t *loop_node)
{
	listint_t *temp;
	size_t size = 0;

	do {
		size++;
		loop_node = loop_node->next;
	} while (loop_node != head);

	while (size > 0)
	{
		temp = head;
		head = head->next;
		free(temp);
		size--;
	}
}

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the head of the list.
 * Return: The size of the list that was freed.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *loop_node, *temp;

	loop_node = find_loop(*h);

	if (loop_node != NULL)
	{
		/* Free nodes before the loop */
		size = 0;
		while (*h != loop_node)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
			size++;
		}

		free_nodes_after_loop(*h, loop_node);
	}
	else
	{
		/* No loop, free the whole list */
		while (*h != NULL)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
			size++;
		}
	}

	return (size);
}
