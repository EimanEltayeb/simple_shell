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
 * command_line - excutes command
 * @result: result.
 * @program: program name
 * @line: line used
 * Return: result
 */
int command_line(int result, char *program, char *line)
{
	int i = 0;
	ssize_t l = 0;
	size_t n = 0;
	char **arr, *token, *ex = "exit", *env = "env";

	while (1)
	{
		i = 0;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		l = getline(&line, &n, stdin);
		if (l == -1)
			break;
		if (l == 1 || (l == 2 && line[0] == '\n'))
			continue;
		arr = (char **)malloc(n * sizeof(char *));
		token = strtok(line, " \n\t");
		while (token != NULL)
		{
			arr[i++] = strdup(token);
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
			result = built(arr);
			break;
		}
		if (strcmp(arr[0], env) == 0)
		{
			result = built(arr);
			continue; }
		result = excute(arr, program); }
	if (line != NULL)
		free(line);
	return (result); }
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
		return (0);
	path = path_function(arr[0]);
	if (path == NULL)
	{
		error_msg(arr, error);
		return (127);
	}
	else if (access(path, X_OK) != 0)
	{
		error_permission(arr, error);
		return (2);
	}
	else
	{
		child = fork();
		if (child == 0)
		{
			if (execve(path, arr, NULL) == -1 && arr[0][0] != ' ')
			{
				error_msg(arr, error);
				return (127);
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
	return (0);
}
/**
 * free_memory - frees memory
 * @arr: array to be freed
 *
 * Return: void
 */

void free_memory(char **arr)
{
	int j;

	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
}
/**
 * main - main code
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, char *argv[])
{
	int result = 0;
	char *line = NULL;

	result = command_line(result, argv[0], line);
	if (line != NULL)
		free(line);
	if (!(isatty(STDIN_FILENO)) && result != 0)
		exit(result);
	return (0);
}
