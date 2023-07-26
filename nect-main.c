#include "main.h"
/**
 * display_shell_prompt - Displays the command prompt.
 * This func is responsible for displaying command prompt on screen.
 * If the standard input is associated with a terminal (interactive mode),
 * it will print the prompt.
 * The prompt format is: " $ ".
 */
void display_shell_prompt(void)
{
	/* Display the prompt */
	if (isatty(STDIN_FILENO) == 1)
	{
		convention_puts(" $ ");
	}
}
/**
 * handle_error - Handles error conditions and exits.
 * @message: The error message to display.
 * This func handles error conditions by printing an error msg
 * and terminating the program with a failure exit code.
 */
void handle_error(const char *message)
{
	/* Print error message and exit */
	perror(message);
	exit(EXIT_FAILURE);
}
/**
 * handle_misc_errors - Handles other error conditions.
 * This func is responsible for handling miscellaneous error conditions
 * that may arise during the program's execution
.* Handles the specific error case of a line being too long and prints
 * an error message to the standard error output.
 */
void handle_misc_errors(void)
{
	/* Handle other error conditions, such as line length exceeding a limit */
	const char error_msg[] = "Error: Line too long\n";
	size_t msg_length = convention_strlen(error_msg) - 1;

	write(STDERR_FILENO, error_msg, msg_length);
}
/**
 * main - Entry point of the program.
 * Return: Always 0.
 */
int main(void)
{
	char *user_input = NULL;
	ssize_t read_status;
	size_t buffer_size = 0;
	char **cmd_args = NULL;

	while (1)
	{
		display_shell_prompt();
		read_status = getline(&user_input, &buffer_size, stdin);
		if (read_status == -1)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		else if (read_status == -2)
		{
			handle_misc_errors();
			continue;  /* Skip executing the command and go back to the prompt */
		}
		else
		{
			user_input[read_status - 1] = '\0'; /* Remove the newline character */
			cmd_args = navigate_line(user_input);
			if (cmd_args[0] != NULL)
			{
				implement_command(cmd_args[0], cmd_args);
			}
			free(cmd_args);
		}
	}
	free(cmd_args);
	return (0);
}
