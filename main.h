#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;


char **navigate_line(char *line);
int implement_command(char *command, char **arg_list);
int convention_putchar(char ch);
void display_shell_prompt(void);
void convention_puts(char *str);
size_t convention_strlen(const char *str);
void handle_error(const char *message);
void handle_misc_errors(void);
int convention_strcmp(const char *str1, const char *str2);
void *my_memcpy(void *destination, const void *source, size_t size);
void implement_child_procedure(char **arg_list);
int convention_atoi(const char *str);
#endif
