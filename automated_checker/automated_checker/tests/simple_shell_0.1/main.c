#include "main.h"
/**
 * excute - excutes the programm
 * @arr: array containing command
 *
 * Return: void
 */

void excute(char **arr)
{
	pid_t child;
	int status, j;

	child = fork();
	if (child == 0)
	{
		execve(arr[0], arr, NULL);
		write(1, "\n", 1);
	}
	else
	{
		wait(&status);
	}
	for (j = 0; arr[j] != NULL; j++)
		free(arr[j]);
	free(arr);
}
/**
 * main - main code
 *
 * Return: 0
 */

int main(void)
{
	char *line, **arr, *token;
	size_t n = 0;
	int i = 0;
	ssize_t l = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		l = getline(&line, &n, stdin);
		if (l == -1)
			break;
		arr = (char **)malloc(n * sizeof(char *));
		token = strtok(line, " \n\t");
		while (token != NULL)
		{
			arr[i] = strdup(token);
			token = strtok(NULL, " \n\t");
			i++;
		}
		arr[i] = NULL;
		excute(arr);
		i = 0;
	}
	free(line);
	return (0);
}

