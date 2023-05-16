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
#define ARGS_LIMIT 64
void execute_command(char *);
void print_string(const char *);
void exit_program(void);
int string_compare(char *string_1, char *string_2);
extern char **environ;
void print_env(void);
ssize_t ashell_getline(char **line_ptr, size_t *buf_size, int fd);

#endif
