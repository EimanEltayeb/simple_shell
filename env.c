#include "main.h"
/**
 * built - a function that checks built-in fnction
 * @arr: arguments array
 * @env: environ
 * Return: exit status
*/
int built(char **arr, char **env)
{
	int i = 0, len = 0, n;
	char *en = "env", /***env = environ*/*ex = "exit";

	if (strcmp(en, arr[0]) == 0)
	{
		while (env[i] != NULL)
		{
			len = strlen(env[i]);
			write(1, env[i], len);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	else if (strcmp(ex, arr[0]) == 0)
	{
		if (arr[1] == NULL)
		{
			free_memory(arr);
			return (0);
		}
		if (atoi(arr[1]) < 1)
		{
			write(2, "./hsh: 1: exit: Illegal number: ", 32);
			write(2, arr[1], strlen(arr[1]));
			write(2, "\n", 1);
			free_memory(arr);
			return (2); }

				n = atoi(arr[1]);
				if (n > 232)
					n = 232;
				free_memory(arr);
				return (n);
	}
	return (-1);
}

/**
 * comment - remove comments from command line
 * @line: command line
 * Return: line without comment.
 */
char *comment(char *line)
{
	char *token_com, *hash = "#";

	if (line[0] == '#')
		return (hash);
	token_com = _strtok(line, "#");
	return (token_com);
}
