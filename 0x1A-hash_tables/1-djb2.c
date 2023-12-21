#include "hash_tables.h"

/**
 * hash_djb2 - DJB2 hash algorithm for strings.
 *
 * Description:
 *     This function calculates a hash value for the given
 *     string using the DJB2 hash algorithm.
 *     The algorithm iterates through each character in the string, updating
 *     the hash value based on the current character and the previous.
 *
 * @str: A pointer to the null-terminated string for which the hash.
 *
 * Return: The calculated hash value for the input string.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
