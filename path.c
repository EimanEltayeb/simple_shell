#include "main.h"
/**
 * path_function - to find the path of a command
 * @cmnd: the command
 * Return: the path or NULL.
*/

char *path_function(char *cmnd)
{
	char *path = NULL, *path_test = NULL, *cpy_path = NULL, **env = environ;
	char *token_path = NULL;
	int len;
	struct stat st;
	env_list *head;

	if (stat(cmnd, &st) == 0)
	{
		path_test = strdup(cmnd);
		return (path_test);
	}
	len = strlen(cmnd);
	head = env_struct(env);
	path = _getenv("PATH", head);
	if (path == NULL)
	{
		return (NULL);
	}
	cpy_path = strdup(path);
	token_path = strtok(cpy_path, ":");
	while (token_path != NULL)
	{
		path_test = malloc(sizeof(char) * (strlen(token_path) + len + 2));
		strcpy(path_test, token_path);
		strcat(path_test, "/");
		strcat(path_test, cmnd);
		if (stat(path_test, &st) == 0)
		{
			free(cpy_path);
			return (path_test);
		}
		else
		{
		free(path_test);
		token_path = strtok(NULL, ":");
		}
	}
		free(cpy_path);
		return (NULL);
}

/**
 * error_msg - handle the error message
 * @error: file name
 * @arr: array of arguments
 * Return: -1
 *
*/
int error_msg(char **arr, char *error)
{
	int j;

	for (j = 0; arr[j + 1] != NULL; j++)
		;
	write(2, error, strlen(error));
	write(2, ": 1: ", 5);
	write(2, arr[0], strlen(arr[0]));
	write(2, ": not found", 11);
	write(2, "\n", 1);
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (0);
}

/**
 * error_permission - handle the error message
 * @error: file name
 * @arr: array of arguments
 * Return: -1
 *
*/
int error_permission(char **arr, char *error)
{
	int j;

	write(2, error, strlen(error));
	write(2, ": Permission denied", 19);
	write(2, "\n", 1);
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (0);
}