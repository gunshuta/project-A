#include "main.h"
/**
 * _strcpy - string copy
 * @dest: destinatiom
 * @src: source
 * Return: Always 1
 */
char *_strcpy(char *dest, char *src)
{
	char *result = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (result);
}
/**
 * _strdup - string duplicate
 * @str: string
 * Return: Always 1
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *new_str;
	const char *p;

	if (!str)
		return (NULL);
p = str;

	while (*p++)
		len++;
	new_str = malloc(len + 1);

	if (!new_str)
		return (NULL);
	_strcpy(new_str, (char *)str);
	return (new_str);
}
/**
 * _puts - shell print function
 * @str: string
 * Return: Always 1
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - shell print character
 * @c: character
 * Return: Always 1
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int pos;

	if (c == '\n' || pos == 1023)
	{
		buffer[pos] = '\n';
		pos++;
		write(1, buffer, pos);
		pos = 0;
	}
	else
	{
		buffer[pos] = c;
		pos++;
	}
	return (1);
}
