#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there is an invalid character
 *         in the string or if the string is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	/* Iterate through the string */
	while (*b)
	{
		/* Check if the character is not 0 or 1 */
		if (*b != '0' && *b != '1')
			return (0);

		/* Calculate the result */
		result = result * 2 + (*b - '0');

		b++;
	}

	return (result);
}
