#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *byte_pointer = (unsigned char *)&num;

	/* If the least significant byte contains 1, the system is little endian */
	return (*byte_pointer == 1);
}
