#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *path_function(char *cmnd);
int error_msg(char **arr, char *error);
int error_permission(char **arr, char *error);
int is_empty(const char *str);

#endif
