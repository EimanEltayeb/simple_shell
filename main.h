#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
 * struct env_list - struct of environment
 * @var: the variable of env
 * @value: the value of the variable
 * @next: the pointer to the next list
*/
extern char **environ;
typedef struct env_list
{
	char *var;
	char *value;
	struct env_list *next;
} env_list;

env_list *env_struct(char **env);
char *path_function(char *cmnd);
int error_msg(char **arr, char *error);
int error_permission(char **arr, char *error);
int is_empty(const char *str);
char *_getenv(const char *variable, env_list *head);
int built(char **arr);
void free_memory(char **arr);
int excute(char **arr, char *error);
char *_strtok(char *str, const char *delim);



#endif
