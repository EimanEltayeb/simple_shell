#include "main.h"
/**
 * _setenv - add a variable to environment.
 * @arr: array
 * Return: int
*/
int _setenv(char **arr, char **env)
{
	int result;

	(void)env;
	result = setenv(arr[1], arr[2], 1);
	if (result == 0)
		return (0);
	write(2, "./hsh: 1: ", 10);
	write(2, arr[0], _strlen(arr[0]));
	write(2, "\n", 1);
	return (2);
}

/**
 * _unsetenv - deletes the variable name from env
 * @arr: array
 * Return: int
*/
int _unsetenv(char **arr, char **env)
{
	int result;

	(void)env;
	result = unsetenv(arr[1]);
	if (result == 0)
	return (0);
	else
	{
		perror("unset");
		return (2);
	}
}
