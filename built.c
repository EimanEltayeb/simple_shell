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
		if (result != 0)
		{
			write(2, "./hsh: 1: ", 9);
			write(2, "cd: can't cd to ", 16);
			write(2, path, _strlen(path));
			write(2, "\n", 1);
		}
		setenv("PWD", path, 1);
		return (result);
	}
	else if (_strcmp(arr[1], dash) == 0)
	{
		path = getenv("OLDPWD");
		result = chdir(path);
		if (setenv("PWD", path, 1) != 0)
		{
			write(2, "./hsh: 1: ", 9);
			write(2, "cd: can't cd to ", 16);
			write(2, arr[1], _strlen(path));
			write(2, "\n", 1);
		}
		else
		{
			write(1, path, _strlen(path));
		}

	}
	else
	{
		result = chdir(arr[1]);
		if (result != 0)
		{
			write(2, "./hsh: 1: ", 9);
			write(2, "cd: can't cd to ", 16);
			write(2, arr[1], _strlen(path));
			write(2, "\n", 1);
		}
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

	if (_strcmp(arr[0], en) == 0)
	{
		result = built(arr);
		return (result);
	}
	if (_strcmp(arr[0], ccd) == 0)
	{
		result = _cd(arr);
		free_memory(arr);
		return (result);
	}
	else
	return (0);
}
