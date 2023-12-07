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
    int sum;  /* Variable to store the sum of elements */

    sum = 0;  /* Initialize sum to zero */

    /* If the list is not empty, move to the beginning of the list */
    if (head != NULL)
    {
        while (head->prev != NULL)
            head = head->prev;

        /* Traverse the list and calculate the sum of elements */
        while (head != NULL)
        {
            sum += head->n;
            head = head->next;
        }
    }

    return (sum);  /* Return the sum of elements in the list */
}
