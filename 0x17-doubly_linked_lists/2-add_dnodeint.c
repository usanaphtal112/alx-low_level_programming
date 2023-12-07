#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 *
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node, or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new;  /* Pointer to the newly created node */
    dlistint_t *h;    /* Temporary pointer to traverse the list */

    /* Allocate memory for the new node */
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    /* Initialize the new node with the provided data */
    new->n = n;
    new->prev = NULL;

    /* Assign the current head to a temporary pointer */
    h = *head;

    /* If the list is not empty, move to the beginning of the list */
    if (h != NULL)
    {
        while (h->prev != NULL)
            h = h->prev;
    }

    /* Connect the new node to the current head and update the head */
    new->next = h;

    if (h != NULL)
        h->prev = new;

    *head = new;

    return (new);  /* Return a pointer to the newly added node */
}
