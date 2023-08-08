#include "main.h"
#include <stdlib.h>
#include <fcntl.h>

/**
 * create_file - Create a file with specified content.
 * @filename: The name of the file to be created.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;

if (filename == NULL)
{
return (-1);
}

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
{
return (-1);
}

if (text_content != NULL)
{
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
}

close(fd);
return (1);
}
