#ifndef SYS_HEADERS_H
#define SYS_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <stddef.h>
#define ARGS_LIMIT 1024
#define ER_MSG "%s: %d: %s: not found\n"
#define BUF_SIZE 128

extern char **environ;
void execute_command(char *,  int, char *);
void print_string(const char *);
void exit_program(int status);
int string_compare(char *string_1, char *string_2);
void print_env(void);
ssize_t _getline(char **line_ptr, size_t *buf_size, FILE *);
ssize_t read_chars(char **, size_t *, char *, size_t *, size_t *, FILE *);
char *_strtok(char *string, char *delimeter);
char *execute_from_path(char *cmd_name);
size_t string_length(const char *str);
void print_integer(int number);
void print_error(int session_counter, char *args[], char *);
int string_toint(char *str);
int built_infunction(int argc, char *args[], int, char *, int *);
int exec_path(char *args[], int s_count, char *pg_name, int *);
void _path(char *args[], char *, int s_count, char *pg_name, int *);
ssize_t __getline(char **lineptr, size_t *n, FILE *stream);

#endif
