#include "main.h"
/**
 * _setenv - add a variable to environment.
 * @arr: array
 * Return: int
*/
int _setenv(char **arr)
{
	int result;

	result = setenv(arr[1], arr[2], 1);
	if (result == 0)
		return (0);
	perror("setenv");
	return (2);
}

/**
 * _unsetenv - deletes the variable name from env
 * @arr: array
 * Return: int
*/
int _unsetenv(char **arr)
{
	int result;

	result = unsetenv(arr[1]);
	if (result == 0)
	return (0);
	else
	{
		perror("unset");
		return (2);
	}
}
/**
 * envlist_free - free the envlist
 *
*/
int envlist_free(env_list *head)
{
	env_list *temp;

	while (temp != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->var);
		free(temp->value);
		free(temp);
	}
	return (0);
}
