#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index in a doubly linked list.
 *
 * @h: A pointer to a pointer to the head of the doubly linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node, or NULL if memory allocation fails
 *         or if the index is out of range.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new;  /* Pointer to the newly created node */
    dlistint_t *head; /* Temporary pointer to traverse the list */
    unsigned int i;    /* Variable to track the current index */

    new = NULL;

    /* Check if the index is 0, and add the node at the beginning */
    if (idx == 0)
        new = add_dnodeint(h, n);
    else
    {
        head = *h;
        i = 1;

        /* If the list is not empty, move to the beginning of the list */
        if (head != NULL)
            while (head->prev != NULL)
                head = head->prev;

        /* Traverse the list to find the insertion point */
        while (head != NULL)
        {
            if (i == idx)
            {
                /* Insert the new node at the specified index */
                if (head->next == NULL)
                    new = add_dnodeint_end(h, n);
                else
                {
                    new = malloc(sizeof(dlistint_t));
                    if (new != NULL)
                    {
                        new->n = n;
                        new->next = head->next;
                        new->prev = head;
                        head->next->prev = new;
                        head->next = new;
                    }
                }
                break;
            }
            head = head->next;
            i++;
        }
    }

    return (new);  /* Return a pointer to the newly added node */
}