#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at a given index in a doubly linked list.
 *
 * @head: A pointer to the head of the doubly linked list.
 * @index: The index of the node to retrieve (starting from 0).
 *
 * Return: A pointer to the node at the specified index, or NULL if the index is
 *         out of range or if the list is empty.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int size;  /* Variable to store the size of the list */
    dlistint_t *tmp;    /* Temporary pointer to traverse the list */

    size = 0;

    /* Check if the list is empty */
    if (head == NULL)
        return (NULL);

    tmp = head;

    /* Traverse the list to find the node at the specified index */
    while (tmp)
    {
        if (index == size)
            return (tmp);

        size++;
        tmp = tmp->next;
    }

    return (NULL);  /* Return NULL if the index is out of range or list is empty */
}
