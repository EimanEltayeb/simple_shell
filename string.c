#include "main.h"
/**
 * _strlen - return string's length
 * @s: the string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != 0)
		len++;
	return (len);
}

/**
 * _strcat - concantenates two strings
 * @dest: destination string
 * @src: source string
 * Return: linked string
 */
char *_strcat(char *dest, char *src)
{
	int dsize = 0;
	int ssize = 0;
	int i;

	while (dest[dsize] != 0)
		dsize++;
	while (src[ssize] != 0)
		ssize++;

	for (i = dsize; i < (dsize + ssize + 1); i++)
		dest[i] = src[i - dsize];
	return (dest);
}


/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: comp status. 0 if the are the same.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int x;

	while (s1[i] != 0 && s2[i] != 0)
	{
		x = s1[i] - s2[i];
		if (x == 0)
			i++;
		else
			break;
	}
	return (x);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	char *s;
	int i, size = 0;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		size++;
	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		s[i] = str[i];
	s[size] = '\0';
	return (s);
}

/**
 * _atoi - converts string to integer
 * @s: string to be converted
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0;
	double num = 0;
	int sign = 1;

	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			num = num * 10 + (s[i] - '0');
		else if (s[i] == '-')
			sign *= -1;
		if (num > 0 && s[i] == ' ')
			break;
		i++;
	}
	return (num * sign);
}
