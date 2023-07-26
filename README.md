This repository contains a basic implementation of a shell in C, providing users with a command-line interface to execute various commands. The goal of this project is to create a simple, functional shell that can handle basic commands and additional features commonly found in Unix-like shells.

Features

The implemented shell comes with the following features:

Command Execution: Users can enter commands in the shell, and the program will execute them using the appropriate system calls and libraries.

Built-in Commands: The shell supports built-in commands like cd to change directories. This allows users to navigate the file system within the shell itself.

External Commands: The shell can execute external commands by using the fork and exec system calls to spawn new processes for each command.

Background Processes: Users can launch commands in the background by appending the & symbol at the end of the command. The shell will continue to accept new commands without waiting for the background process to complete.

Input/Output Redirection: Basic input/output redirection is supported using the dup2 system call. Users can redirect input from a file or output to a file using the < and > operators, respectively.

Pipes: The shell allows the use of pipes (|) to chain multiple commands together, enabling more complex command combinations.

