#include "main.h"
/**
 * is_empty - checks if string is empty
 * @str: string to be checked
 *
 * Return: 1 if empty 0 if not
 */

int is_empty(const char *str)
{
	while (*str != '\0')
	{
	if (*str != ' ')
	{
		return (0);
	}
	str++;
	}
	return (1);
}
/**
 * excute - excutes the programm
 * @arr: array containing command
 * @error: program name
 *
 * Return: void
 */
int excute(char **arr, char *error)
{
	pid_t child;
	int status, j;
	char *path;

	if (arr[0] == NULL || arr[0][0] == '\0')
	{
		return (0);
	}
	path = path_function(arr[0]);
	if (path == NULL)
	{
		error_msg(arr, error);
		return(0);
	}
	else if(access(path, X_OK) != 0)
	{
		error_permission(arr, error);
		return (0);
	}
	else
	{	
		child = fork();
		if (child == 0)
		{
			if (execve(path, arr, NULL) == -1 && arr[0][0] != ' ')
			{
				error_msg(arr, error);
				return (0);
			}
				write(1, "\n", 1);
			}
			else
			{
				wait(&status);
			}
			free(path);
		for (j = 0; arr[j] != NULL; j++)
			free(arr[j]);
		free(arr);
		}
	return(0);
}
/**
 * main - main code
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *line = NULL, **arr, *token, *ex = "exit";
	size_t n = 0;
	int i = 0, j/*, result = 0*/;
	ssize_t l = 0;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		l = getline(&line, &n, stdin);
		if (l == -1)
		{
			break;
		}
		if (l == 1 || (l == 2 && line[0] == '\n'))
		{
			continue;
		}
		arr = (char **)malloc(n * sizeof(char *));
		token = strtok(line, " \n\t");
		while (token != NULL)
		{
			if (token[0] != '\0')
			{
				arr[i] = strdup(token);
				i++;
			}
			token = strtok(NULL, " \n\t");
		}
		arr[i] = NULL;
		if (i == 0)
		{
			free(arr);
			continue;
		}
		if (strcmp(arr[0], ex) == 0)
		{
			for (j = 0; arr[j] != NULL; j++)
					free(arr[j]);
			free(arr);
			break;
		}
		excute(arr, argv[0]);
		i = 0;
	}
	if (line != NULL)
		free(line);
	return (0);
}
