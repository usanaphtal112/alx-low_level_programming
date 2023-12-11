## Task 0: A library is not a luxury but one of the necessities of life

Create the dynamic library `libdynamic.so` containing the following functions:

```c
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);

```

## Task 1: Without libraries what have we? We have no past and no future

Create a script that creates a dynamic library called `liball.so` from all the .c files that are in the current directory.


#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic -shared -fPIC -o liball.so *.c

#### Task 1: Create Dynamic Library from .c Files
Create a script that creates a dynamic library called `liball.so` from all the .c files in the current directory.


#### Task 2: Call C Functions from Python
Create a dynamic library containing C functions that can be called from Python.

- Let's call C functions from Python
  - Create a dynamic library that contains C functions which can be called from Python. See example for more detail.


#### Task 3: Code Injection for Giga Millions
Create a shell script for code injection to win the Giga Millions.

```
- Code injection: Win the Giga Millions!
  - I bought a ticket for the Giga Millions and chose these numbers: 9, 8, 10, 24, 75 + 9.
  - Create a shell script (`101-make_me_win.sh`) to be run on the server with the Giga Millions program.
    - You can't modify the program (`gm`) itself.
    - Maximum 3 lines long, no use of ;, &&, ||, |, `.
    - Upload one file on the server, and mole will run the script 98 seconds before MSS runs `gm` with specified numbers.
    - MSS checks the directory before running `gm` and exits after running.
    - Shell script execution: `mss@gm_server$ . ./101-make_me_win.sh`
