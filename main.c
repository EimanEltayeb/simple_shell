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
 * @line0: line used
 * @env: environ
 * Return: result
 */
int command_line(int result, char *program, char *line0, char **env)
{
	ssize_t l = 0;
	size_t n = 0;
	char **arr, *ex = "exit", *line, *hash = "#";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		l = getline(&line0, &n, stdin);
		if (l == -1)
			break;
		if (l == 1 || (l == 2 && line0[0] == '\n'))
			continue;
		line = comment(line0);
		if (_strcmp(line, hash) == 0)
		continue;
		arr = commandline_cont(arr, n, line);
		if (arr == NULL)
			continue;
		if (_strcmp(arr[0], ex) == 0)
		{
			result = built(arr, env);
			break; }
		if (check_built(arr) == 1)
		{
			result = builtin(arr, env);
			continue; }
		result = excute(arr, program, env); }
	if (line != NULL)
		free(line);
	return (result); }
/**
 * excute - excutes the programm
 * @arr: array containing command
 * @error: program name
 * @env: environ
 * Return: void
 */
int excute(char **arr, char *error, char **env)
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
		return (127); }
	else if (access(path, X_OK) != 0)
	{
		error_permission(arr, error);
		return (2); }
	child = fork();
	if (child == 0)
	{
		if (execve(path, arr, env) == -1 && arr[0][0] != ' ')
		{
			error_msg(arr, error);
			return (127); }
			write(1, "\n", 1); }
		else
		{
			wait(&status); }
		free(path);
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (0); }
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
 * @env: environ
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, char *argv[], char **env)
{
	int result = 0;
	char *line = NULL;

	result = command_line(result, argv[0], line, env);
	if (line != NULL)
		free(line);
	if (!(isatty(STDIN_FILENO)) && result != 0)
		exit(result);
	return (0);
}
