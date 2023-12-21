/*
 * File: 2-key_index.c
 * Author: Naphtal USABYUWERA
 * Desc: Implementation of the key_index
 * function using the DJB2 hash algorithm.
 */

#include "hash_tables.h"

/**
 * key_index - Calculates the index for a given key using the DJB2 hash
 *
 * Description: This function takes a key
 * and a size, and computes the index using the DJB2 hash algorithm.
 * The resulting index is the remainder of the hash value divided
 *
 * @key: The key for which the index is to be calculated.
 * @size: The size of the array or structure where the key will be stored.
 *
 * Return: The calculated index for the given key within the specified size.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
