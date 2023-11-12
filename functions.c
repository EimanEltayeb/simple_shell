#include "main.h"

/**
 * _strtok - works exactly like strtok
 * @str: string to be tokened
 * @delim: delimeters.
 *
 * Return: pointer to string.
 */

char *_strtok(char *str, const char *delim)
{
	static char *save;
	char *token = NULL;

	if (str != NULL)
		save = str;
	if (save == NULL || *save == '\0')
		return (NULL);
	while (*save != '\0' && strchr(delim, *save) != NULL)
	{
		*save = '\0';
		save++;
	}
	if (*save == '\0')
	{
		return (NULL);
	}
	token = save;
	while (*save != '\0' && strchr(delim, *save) == NULL)
		save++;
	if (*save != '\0')
	{
		*save = '\0';
		save++;
	}
	return (token);
}

/**
 * _strcpy - a function to copy a string
 * @dest: destination string
 * @src: source string
 * Return: string 
*/
char *_strcpy(char *dest, char *src)
{
	int size = 0;
	int i;

	while (src[size] != 0)
		size++;
	for (i = 0; i <= size; i++)
		dest[i] = src[i];
	return (dest);
}
