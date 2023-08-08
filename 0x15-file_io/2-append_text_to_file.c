#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/**
 * append_text_to_file - Append text to the end of a file.
 * @filename: The name of the file to which text will be appended.
 * @text_content: The content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
int fd, w, len = 0;
if (filename == NULL)
	return (-1);

if (text_content == NULL)
	return (1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
{
return (-1);
}

while (text_content[len])
{
len++;
}

w = write(fd, text_content, len);
if (w == -1 || w != len)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
