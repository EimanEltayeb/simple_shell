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
char *_getenv(char *variable, env_list *head)
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
 * @arr: argv
 * Return: exit status
*/
int built(char **arr)
{
	int i = 0, len = 0, n;
	char *en = "env", **env = environ, *ex = "exit";

	if (strcmp(en, arr[0]) == 0)
	{
		while (env[i] != NULL)
		{
			len = strlen(env[i]);
			write(1, env[i], len);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	else if (strcmp(ex, arr[0]) == 0)
	{
		if (arr[1] == NULL)
		{
			free_memory(arr);
			return (0);
		}
		if (atoi(arr[1]) < 1)
		{
			write(2, "./hsh: 1: exit: Illegal number: ", 32);
			write(2, arr[1], strlen(arr[1]));
			write(2, "\n", 1);
			free_memory(arr);
			return (2); }

				n = atoi(arr[1]);
				if (n > 232)
					n = 232;
				free_memory(arr);
				return (n);
	}
	return (-1);
}

/**
 * comment - remove comments from command line
 * @line: command line
 * Return: line without comment.
 */
char *comment(char *line)
{
	char *token_com, *hash = "#";

	if (line[0] == '#')
		return (hash);
	token_com = _strtok(line, "#");
	return (token_com);
}
