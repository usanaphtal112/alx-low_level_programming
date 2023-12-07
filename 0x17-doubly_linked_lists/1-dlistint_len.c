#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list.
 *
 * @h: A pointer to the head of the doubly linked list.
 *
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
    int count;  /* Variable to store the count of elements */

    count = 0;  /* Initialize count to zero */

    /* Check if the list is empty */
    if (h == NULL)
        return (count);

    /* Move to the beginning of the list */
    while (h->prev != NULL)
        h = h->prev;

    /* Traverse the list and count each element */
    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return (count);  /* Return the count of elements in the list */
}
