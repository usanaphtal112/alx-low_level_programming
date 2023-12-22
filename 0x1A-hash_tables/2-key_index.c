#include "hash_tables.h"

/**
 * Calculates the index for a given key using the DJB2 hash function.
 *
 * This function takes a key (represented as an array of unsigned characters)
 *  and a size, and computes the index using the DJB2 hash algorithm.
 * The resulting index is the remainder
 * of the hash value divided by the specified size.
 *
 * @param key   The key for which the index is to be calculated.
 * @param size  The size of the array or structure where the key
 *
 * @return      The calculated index for the given key within
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
