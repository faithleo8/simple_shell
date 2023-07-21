#include "main.h"
/**
 * parse_line - Parses a line into an array of tokens.
 * @line: The input line to parse.
 * Return: An array of tokens.
 */
char **parse_line(char *line)
{
	const char *delimiters = " \t\r\n\a";
	char **argv = NULL;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delimiters);
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, delimiters);
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * execute_command - Executes a command with its arguments.
 * @command: The command to execute.
 * @argv: An array of arguments for the command.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char **argv)
{
	if (custom_strcmp(command, "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			int status = custom_atoi(argv[1]);

			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (custom_strcmp(command, "env") == 0)
	{
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
		execute_child_process(argv);
	}
	return (0);
}
/**
 * execute_child_process - Executes the child process with the given arguments.
 * @argv: An array of arguments for the command.
 */
void execute_child_process(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		handle_error("fork");
		return;
	}
	else if (pid == 0)
	{
		if (argv[0][0] == '/')
		{
			execve(argv[0], argv, environ);
		}
		else
		{
			char *path = getenv("PATH");
			char *cmd = argv[0];
			char *token;
			char cmd_path[1024];
			size_t path_len, cmd_len;

			while ((token = strtok(path, ":")) != NULL)
			{
				path_len = custom_strlen(token);
				cmd_len = custom_strlen(cmd);
				/* Construct the full path of the command*/
				custom_memcpy(cmd_path, token, path_len);
				cmd_path[path_len] = '/';
				custom_memcpy(cmd_path + path_len + 1, cmd, cmd_len);
				cmd_path[path_len + cmd_len + 1] = '\0';

				execve(cmd_path, argv, environ);
				path = NULL;  /* Reset path for subsequent calls to strtok*/
			}
		}
		handle_error("execve");
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);  /* Wait for child process to complete*/
}
/**
 * custom_memcpy - Copy memory area
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to copy
 * Return: Pointer to the destination memory area
 */
void *custom_memcpy(void *dest, const void *src, size_t n)
{
	char *dest_ptr = (char *)dest;
	const char *src_ptr = (const char *)src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		dest_ptr[i] = src_ptr[i];
	}
	return (dest);
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
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handling leading whitespace */
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	/* Handling sign */
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	/* Converting digits to integer */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
