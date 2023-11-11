#include "main.h"
/**
 * _cd - change directory function
 * @arr: the arguments array
 * Return: int
*/
int _cd(char **arr)
{
	int result = 0;
	char *path = NULL, *old = NULL, *now = NULL, *dash = "-";

	now = _strdup(getenv("PWD"));
	old = _strdup(getenv("OLDPWD"));
	if (arr[1] == NULL)
	{
		path = getenv("HOME");
		result = chdir(path);
		if (result != 0)
			error_cd(arr);
		setenv("PWD", path, 1);
		setenv("OLDPWD", now, 1); }
	else if (_strcmp(arr[1], dash) == 0)
	{
		path = old;
		result = chdir(path);
		if (result != 0)
			error_cd(arr);
		else
		{
			setenv("PWD", path, 1);
			setenv("OLDPWD", now, 1);
			write(1, path, _strlen(path));
			write(1, "\n", 1); }
	}
	else
	{
		path = arr[1];
		result = chdir(path);
		if (result != 0)
			error_cd(arr);
		setenv("PWD", path, 1);
		setenv("OLDPWD", now, 1);
	}
	free(now);
	free(old);
	return (result);
}
/**
 * error_cd - handles the cd errors
 * @arr: array of command
*/
void error_cd(char **arr)
{
	write(2, "./hsh: 1: ", 9);
	write(2, " cd: can't cd to ", 17);
	write(2, arr[1], _strlen(arr[1]));
	write(2, "\n", 1);
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
