#include "main.h"

/**
 * parse_line - Parses a line into an array of tokens.
 * @line: The input line to parse.
 * Return: An array of tokens.
 */
char **parse_line(char *line)
{
const char *delimiters = " \t\r\n\a";
char **token_array = NULL;/* Array to store tokens*/
char *current_token;/*Pointer to the current token*/
int token_count = 0;/*Counter for the number of tokens*/

token_array = malloc(sizeof(char *) * 64);
/*Allocate memory for the token array*/
if (token_array == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

current_token = strtok(line, delimiters);/*Get the first token*/
while (current_token != NULL)
{
token_array[token_count] = current_token;
/*Store the current token in the array*/
token_count++;/*Increment the token count*/
current_token = strtok(NULL, delimiters);/*Get the next token*/
}
token_array[token_count] = NULL;
/*Set the last element of the array to NULL to mark the end*/

return (token_array);/*Return the array of tokens*/
}
/**
 * execute_command - Executes a command with its arguments.
 * @command: The command to execute.
 * @arg_list: An array of arguments for the command.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char **arg_list)
{
if (custom_strcmp(command, "exit") == 0)
{
if (arg_list[1] != NULL)
{
/*If an argument is provided, convert it to an integer and exit*/
int exit_status = custom_atoi(arg_list[1]);
exit(exit_status);
}
else
{
/*If no argument is provided, exit with success status*/
exit(EXIT_SUCCESS);
}
}
else if (custom_strcmp(command, "env") == 0)
{
/*Print the environment variables*/
char **env = environ;
while (*env != NULL)
{
custom_puts(*env);
custom_putchar('\n');
env++;
}
return (0);
}
else
{
/* Execute the command as a child process*/
execute_child_process(arg_list);
}
return (0);
}
/**
 * execute_child_process - Executes the child process with the given arguments.
 * @arg_list: An array of arguments for the command.
 */
void execute_child_process(char **arg_list)
{
pid_t child_pid = fork();
int status;

if (child_pid == -1)
{
handle_error("fork");
return;
}
else if (child_pid == 0)
{
if (arg_list[0][0] == '/')
{
execve(arg_list[0], arg_list, environ);
}
else
{
char *path_env = getenv("PATH");
char *command = arg_list[0];
char *path_token;
char command_path[1024];
size_t path_len, command_len;

while ((path_token = strtok(path_env, ":")) != NULL)
{
path_len = custom_strlen(path_token);
command_len = custom_strlen(command);
/* Construct the full path of the command */
my_memcpy(command_path, path_token, path_len);
command_path[path_len] = '/';
my_memcpy(command_path + path_len + 1, command, command_len);
command_path[path_len + command_len + 1] = '\0';

execve(command_path, arg_list, environ);
path_env = NULL;  /* Reset path_env for subsequent calls to strtok */
}
}
handle_error("execve");
exit(EXIT_FAILURE);
}
waitpid(child_pid, &status, 0);  /* Wait for child process to complete */
}
/**
 * my_memcpy - Copy memory area.
 * @destination: Pointer to the destination memory area.
 * @source: Pointer to the source memory area.
 * @size: Number of bytes to copy.
 * Return: Pointer to the destination memory area.
 */
void *my_memcpy(void *destination, const void *source, size_t size)
{
char *dest_ptr = (char *)destination;/*Pointer to destination memory area*/
const char *src_ptr = (const char *)source;/*Pointer to source memory area*/
size_t i;

for (i = 0; i < size; i++)
{
dest_ptr[i] = src_ptr[i];/*Copy each byte from source to destination*/
}
return (destination);/*Return pointer to the destination memory area*/
}
/**
 * custom_atoi - Converts a string to an integer.
 * @str: The input string to convert.
 *
 * This function converts the given string @str to an integer.
 * It skips leading whitespace characters, handles the sign,
 * and converts the digits to an integer value.
 *
 * Return: The converted integer value.
 */
int custom_atoi(const char *str)
{
int output = 0;
int sign = 1;
int index = 0;

/* Handling leading whitespace */
while (str[index] == ' ' || str[index] == '\t')
{
index++;
}
/* Handling sign */
if (str[index] == '-')
{
sign = -1;
index++;
}
else if (str[index] == '+')
{
index++;
}

/*Conversion of digits to integer value*/
while (str[index] >= '0' && str[index] <= '9')
{
output = (output * 10) + (str[index] - '0');
index++;
}
return (sign *output);
}
