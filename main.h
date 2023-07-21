#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char **parse_line(char *line);
int execute_command(char *command, char **argv);
int custom_putchar(char ch);
void prompt(void);
void custom_puts(char *str);
size_t custom_strlen(const char *str);
void handle_error(const char *message);
void handle_other_errors(void);
int custom_strcmp(const char *str1, const char *str2);
void *custom_memcpy(void *dest, const void *src, size_t n);
void execute_child_process(char **argv);
int custom_atoi(const char *str);

#endif
