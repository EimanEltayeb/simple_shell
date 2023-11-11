#include "main.h"
/**
 * _cd - change directory function
 * @arr: the arguments array
 * Return: int
*/
int _cd(char **arr)
{
	int result;
	char *path, *dash = "-";

	if (arr[1] == NULL)
	{
		path = getenv("HOME");
		result = chdir(path);
		if (setenv("PWD", path, 1) != 0)
		{
			write(2, "./hsh: 1: ", 9);
			perror("chdir");
		}
		return (result);
	}
	if (strcmp(arr[1], dash) == 0)
	{
		path = getenv("OLDPWD");
		if (setenv("PWD", path, 1) != 0)
		{
			write(2, "./hsh: 1: ", 9);
			perror("chdir");
		}

	}
	result = chdir(arr[1]);
	if (result != 0)
	{
		write(2, "./hsh: 1: ", 9);
		perror("chdir");
	}
	return (result);
}

/**
 * builtin - handle builtin commands
 * @arr: command line arguments
 * Return: result.
*/
int builtin(char **arr)
{
	int result;
	char *en = "env", *ccd = "cd";

	if (strcmp(arr[0], en) == 0)
	{
		result = built(arr);
		return (result);
	}
	if (strcmp(arr[0], ccd) == 0)
	{
		result = _cd(arr);
		free_memory(arr);
		return (result);
	}
	else
	return (0);
}
