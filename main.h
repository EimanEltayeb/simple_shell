#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

char *path_function(char *cmnd);
int error_msg(char **arr, char *error);
int error_permission(char **arr, char *error);
int is_empty(const char *str);
int built(char **arr, char **env);
void free_memory(char **arr);
int excute(char **arr, char *error, char **env);
char *_strtok(char *str, const char *delim);
int _cd(char **arr);
char *comment(char *line);
int builtin(char **arr, char **env);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _atoi(char *s);
void error_cd(char **arr);
char *_strcpy(char *dest, char *src);
int check_built(char **arr);
int _setenv(char **arr);
int _unsetenv(char **arr);
char **commandline_cont(char **arr, size_t n, char *line);

#endif
