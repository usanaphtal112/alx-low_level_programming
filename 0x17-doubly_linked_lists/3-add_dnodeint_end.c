#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 *
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node, or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *h;    /* Temporary pointer to traverse the list */
    dlistint_t *new;  /* Pointer to the newly created node */

    /* Allocate memory for the new node */
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    /* Initialize the new node with the provided data */
    new->n = n;
    new->next = NULL;

    /* Assign the current head to a temporary pointer */
    h = *head;

    /* If the list is not empty, move to the end of the list */
    if (h != NULL)
    {
        while (h->next != NULL)
            h = h->next;

        /* Connect the new node to the end of the list */
        h->next = new;
    }
    else
    {
        /* If the list is empty, the new node becomes the head */
        *head = new;
    }

    /* Set the previous pointer of the new node to the current last node */
    new->prev = h;

    return (new);  /* Return a pointer to the newly added node */
}
