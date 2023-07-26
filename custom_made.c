#include "main.h"
/**
 * convention_puts - Print a string
 * @str: The string to be printed
 *
 * This function outputs a string. It iterates thru each char of str
 * and uses the custom_putchar function to print it if it is not Null.
 *
 * Return: None
 */
void convention_puts(char *str)
{
if (str != NULL)/*Function implementation begins.*/
{
char *current_char = str;
/*Iterate char of str till the null terminator is reached.*/
while (*current_char != '\0')
{
convention_putchar(*current_char);
/*Call convention_putchar to print the current character.*/
current_char++;/*Move to the next char in str*/
}
}
}
/**
 * convention_putchar - Write a character to stdout
 * @ch: The character to print
 *
 * This function writes a character to the standard output using the write
 * system call. It returns 1 on success and -1 on error.
 * @ch: The character to print
 * Return: 1 on success, -1 on error
 */
int convention_putchar(char ch)
{
return (write(1, &ch, 1));
/*It writes the character 'ch' to the standard output (file descriptor 1).*/
/*The function returns the number of characters written (1 in this case).*/
}
/**
 * convention_strlen -formulates the length of str
 * @str: The str to calculate
 *
 * This func formulates the len of str by counting the no ofchar
 *
 * Return: len of str.
 */
size_t convention_strlen(const char *str)
{
size_t length = 0;

if (str == NULL)/*Check if the string is NULL.*/
{
return (0);/* Return 0 if the string is NULL.*/
}
while (*str != '\0')/*Iterate thru string till the terminator is encountered.*/
{
/*Increment the length and move to the next character in the string.*/
length++;
str++;
}
return (length);
}
/**
 * convention_strcmp - Compare two strings lexicographically
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * Return: Integer less than, equal to, or greater than zero
 */
int convention_strcmp(const char *str1, const char *str2)
{
/*Enter loop till a diff is found or both str.*/
while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
{
/*Move to the next character in both strings.*/
str1++;
str2++;
}
/* Return the diff btw the first differing chars.*/
return (*str1 - *str2);
}
