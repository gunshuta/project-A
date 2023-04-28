#include "main.h"

/**
 * _interactive - returns true if shell is interactive mode
 * @s: address
 * Return: Always 1
 */
int _interactive(char *s)
{
	int i = 1;
	int sign =1;
	int result = 0;

	if (!s || !*s)
	{
		return (0);
	}
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (isdigit(s[i]))
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
	{
		return (0);
	}
	return (sign * result);
}
/**
 * is_interactive - check for program shell is interactive
 * @info: address
 * Return: 1 if interactive
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delimiter - checks character for a delimeter
 * @c: the char to check
 * Return: 1 if true
 */
int is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
/**
 * has_alphabets - checks for alphabetic character
 * @s: input character
 * Return: 1 if true
 */
int has_alphabets(char *s)
{
	while (*s)
	{
		if (isalpha(*s))
		{
			return (1);
		}
		s++;
	}
	return (0);
}
