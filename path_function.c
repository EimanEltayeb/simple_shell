#include "main.h"
/**
 * path_function - to find the path of a command
 * @cmnd: the command
 * Return: the path or NULL.
*/

char *path_function(char *cmnd)
{
	char *path = NULL, *path_test = NULL, *cpy_path = NULL;
	char *token_path = NULL;
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
	cpy_path = strdup(path);
	token_path = strtok(cpy_path, ":");
	while (token_path != NULL)
	{
		path_test = malloc(sizeof(char) * (strlen(token_path) + len + 2));

		strcat(path_test, token_path);
		strcat(path_test, "/");
		strcat(path_test, cmnd);
		strcat(path_test, "\0");

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

	write(2, error, strlen(error));
	write(2, ": 1: ", 6);
	write(2, arr[0], strlen(arr[0]));
	write(2, ": not found\n", 12);
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (-1);
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
	write(2, ": Permission denied\n", 20);
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (-1);
}
