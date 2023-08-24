#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;

int exec_cmd(char **str_arr);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **_strtok(char *str);
char *get_path(char *filename);
char *_getenv(char *name);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);

#endif
