#include "main.h"
/**
 * custom_puts - Print a string
 * @str: The string to be printed
 *
 * This function prints a string to the standard output. If the string is not
 * NULL, it iterates over each character of the string and calls the
 * custom_putchar function to print it.
 *
 * Return: None
 */
void custom_puts(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			custom_putchar(*str);
			str++;
		}
	}
}

/**
 * custom_putchar - Write a character to stdout
 * @ch: The character to print
 *
 * This function writes a character to the standard output using the write
 * system call. It returns 1 on success and -1 on error.
 *
 * Return: 1 on success, -1 on error
 */
int custom_putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * custom_strlen - Calculate the length of a string
 * @str: The string whose length to calculate
 *
 * This function calculates the length of a string by counting the number of
 * characters until the null terminator '\0' is encountered. If the string is
 * NULL, it returns 0.
 *
 * Return: The length of the string
 */
size_t custom_strlen(const char *str)
{
	size_t length = 0;

	if (str == NULL)
		return (0);

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * custom_strcmp - Compare two strings lexicographically
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * This function compares two strings lexicographically. It iterates over each
 * character of the strings until a difference is found or the end of either
 * string is reached. It returns an integer less than, equal to, or greater
 * than zero if str1 is found to be less than, equal to, or greater than str2,
 * respectively.
 *
 * Return: Integer less than, equal to, or greater than zero
 */
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
