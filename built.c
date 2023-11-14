#include "main.h"
/**
 * _cd - change directory function
 * @arr: the arguments array
 * Return: int
*/
int _cd(char **arr)
{
	int result = 0;
	char *path = NULL, *old = NULL, *now = NULL, *dash = "-", buf[100];

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
		{	error_cd(arr);}

		path = getcwd(buf, sizeof(buf));
		if (path == NULL)
			{perror("getcwd");}
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
 * @env: environ
 * Return: result.
*/
int builtin(char **arr, char **env)
{
	int result = 0;
	char *en = "env", *ccd = "cd", *set = "setenv", *unset = "unsetenv";

	if (_strcmp(arr[0], en) == 0)
	{
		result = built(arr, env);
	}
	else if (_strcmp(arr[0], ccd) == 0)
	{
		result = _cd(arr);
	}
	else if (_strcmp(arr[0], set) == 0)
	{
		result =  _setenv(arr);
	}
	else if (_strcmp(arr[0], unset) == 0)
	{
		result = _unsetenv(arr);
	}
	free_memory(arr);
	return (result);
}
/**
 * check_built - check if built ins are true
 * @arr: array
 * Return: int
*/
int check_built(char **arr)
{
	char *en = "env", *cd = "cd", *set = "setenv", *unset = "unsetenv";

	if ((_strcmp(arr[0], en) == 0) || (_strcmp(arr[0], cd) == 0))
		return (1);
	else if ((_strcmp(arr[0], set) == 0) || (_strcmp(arr[0], unset) == 0))
		return (1);
	else
		return (0);
}
