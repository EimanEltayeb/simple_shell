#include "main.h"
/**
 * env_struct - struct a list for environment
 * @env: environment
 * Return: header pointer.
*/
env_list *env_struct(char **env)
{
	int i;
	env_list *new = NULL, *head = NULL, *last = NULL;
	char *token = NULL, *env_cpy = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		env_cpy = strdup(env[i]);
		if (env_cpy == NULL)
			return (NULL);
		token = strtok(env_cpy, "=");
		if (token != NULL)
		{
			new = malloc(sizeof(env_list));
			if (new == NULL)
			{
				free(env_cpy);
				return (NULL);
			}
			new->var = strdup(token);
			token = strtok(NULL, "=");
			if (token != NULL)
				new->value = strdup(token);
			else
				new->value = NULL;
			new->next = NULL;
			if (head == NULL)
			{
				head = new;
				last = new;
			}
			else
			{
				last->next = new;
				last = new;
			}
		}
		free(env_cpy);
	}

return (head);
}

/**
 * _getenv - return the value of a variable from env_list
 * @variable: the variable
 * @head: env_list pointer
 * Return: value of the variable
*/
char *_getenv(const char *variable, env_list *head)
{
	env_list *temp;
	int x = 0;

	temp = head;
	while (temp != NULL)
	{
		x = strcmp(temp->var, variable);
		if (x == 0)
		return (temp->value);
		else
		temp = temp->next;
	}
	return (NULL);
}

/**
 * built - a function that checks built-in fnction
*/
int built(char *cmnd)
{
	int i = 0, len = 0;
	char *en, **env = environ;
	en = "env"; 
	if (strcmp(en, cmnd) == 0)
	{
	while (env[i] != NULL)
	{
		len = strlen(env[i]);
		write(1, env[i], len + 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
	}
	else
	return (-1);
}
