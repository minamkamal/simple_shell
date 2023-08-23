#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 64
extern char **environ;

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *my_which(char *filename);
char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
