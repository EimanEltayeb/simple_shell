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
	static char *save = NULL;
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
