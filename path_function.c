#include "main.h"
/**
 * path_function - to find the path of a command
 * @cmnd: the command
 * Return: the path or NULL.
*/

char *path_function(char *cmnd)
{
	char *path, *path_test;
	char *token_path;
	int len;
	struct stat st;

	if (stat(cmnd, &st) == 0)
	{
		path_test = malloc(sizeof(cmnd));
		path_test = cmnd;
		return (path_test);
	}
	len = strlen(cmnd);
	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	token_path = strtok(path, ":");
	while (token_path != NULL)
	{
		path_test = malloc(sizeof(char) * (strlen(token_path) + len + 2));
		path_test[0] = '\0';
		strcat(path_test, token_path);
		strcat(path_test, "/");
		strcat(path_test, cmnd);
		strcat(path_test, "\0");

		if (stat(path_test, &st) == 0)
		{
		return (path_test);
		}
		else
		{
		free(path_test);
		token_path = strtok(NULL, ":");
		}
	}
		return (NULL);
}
