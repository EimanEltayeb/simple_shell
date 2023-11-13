#include "main.h"
/**
 * commandline_cont - continue the command line function
 * @arr: array of line command
 * @n: size
 * @line: command line
 * Return: array
*/
char **commandline_cont(char **arr, size_t n, char *line)
{
	char *token;
	int i = 0;

	arr = (char **)malloc(n * sizeof(char *));
	token = _strtok(line, " \n\t");
	while (token != NULL)
	{
		arr[i++] = _strdup(token);
		token = _strtok(NULL, " \n\t"); }
		arr[i] = NULL;
		if (i == 0)
		{
			free(arr);
		}
	return (arr);
}
