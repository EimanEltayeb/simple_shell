#include "main.h"
/**
 * _setenv - add a variable to environment.
 * @name: variable name
 * @value: variable value
 * @overwrite: overwrite status
 * Return: int
*/
/*int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strcmp(name, environ[i]) == 0)

	}
	return (0);
}*/

/**
 * _unsetenv - deletes the variable name from env
 * @name: variable name
 * Return: int
*/
/*int _unsetenv(const char *name)
{
	return (0);
}*/
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
