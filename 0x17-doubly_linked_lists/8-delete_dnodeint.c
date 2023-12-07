#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a doubly linked list.
 *
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 if the deletion is successful, -1 if the index is out of range or
 *         if the deletion fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *h1;  /* Pointer to traverse the list */
    dlistint_t *h2;  /* Pointer to keep track of the previous node */
    unsigned int i;   /* Variable to track the current index */

    h1 = *head;

    /* If the list is not empty, move to the beginning of the list */
    if (h1 != NULL)
        while (h1->prev != NULL)
            h1 = h1->prev;

    i = 0;

    /* Traverse the list to find the node at the specified index */
    while (h1 != NULL)
    {
        if (i == index)
        {
            /* Delete the node at the specified index */
            if (i == 0)
            {
                *head = h1->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            }
            else
            {
                h2->next = h1->next;

                if (h1->next != NULL)
                    h1->next->prev = h2;
            }

            free(h1);
            return (1);
        }

        h2 = h1;
        h1 = h1->next;
        i++;
    }

    return (-1);  /* Return -1 if the index is out of range or if the deletion fails */
}
