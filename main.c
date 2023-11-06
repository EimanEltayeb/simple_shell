#include "main.h"
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

	child = fork();
	if (child == 0)
	{
		if (execve(arr[0], arr, NULL) == -1 && arr[0][0] != ' ')
		{
			write(1, error, strlen(error));
			write(1, ": 1: ", 6);
			write(1, arr[0], strlen(arr[0]));
			write(1, ": not found\n", 12);
			for (j = 0; arr[j] != NULL; j++)
				free(arr[j]);
			free(arr);
			return (-1);
		}
		write(1, "\n", 1);
	}
	else
	{
		wait(&status);
	}
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
	return (0);
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
	char *line = NULL, **arr, *token;
	size_t n = 0;
	int i = 0, result = 0;
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
		if (l == 1)
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
		result = excute(arr, argv[0]);
		i = 0;
		if (result == -1 || l == -1)
			break;
	}
	if (line != NULL)
		free(line);
	return (0);
}

