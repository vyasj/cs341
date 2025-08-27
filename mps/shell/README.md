# Shell

## Features:

### Startup flags
1. `-h <file.txt>` will load a history of commands from `file.txt` and start a session that continues from where the history left off. When the session is ended, the shell will append all commands to `file.txt`.
2. `-f <file.txt>` will run all the commands from `file.txt` and end the session afterward.
### Prompt format
`(pid=<pid>)<path>$` where `<pid>` is replaced with the process ID of the shell, and `<path>` is the path to the current directory that the shell is operating in.
### Command execution confirmation
`Command executed by pid=<pid>` where `<pid>` is the process ID of the process that ran the command.
### History
Every command should be stored in a history unless explicitly told otherwise. The shell does not output the history to a file unless provided the `-h` flag.
### `exit`
The shell exits when the `exit` command is run or when it receives an `EOF` at the beginning of a line. `exit` should not be stored in the history.
### `ctrl+C`
The shell should just kill the running foreground process, if there is one. `ctrl-C` should not kill the shell program.
### Built-in commands and proper failure messages on error:
1. `cd <path>` behaves normally
2. `!history` prints out each command in the history, but should not be stored in the shell history
3. `#<n>` prints and executes the `n`th command in the history, which is 0-indexed. Should not be stored in the shell history, but the command that gets run should.
4. `!<prefix>` prints and executes the last command that has the specified prefix. Print the command before executing if there is a match. Should not be stored in the shell history, but the command that gets run should.
### External commands
For non built-in commands, the shell assumes the name of the command is the name of a binary file that can be executed. This gets executed by a subprocess.
### Logical operators
Supports `&&`, `||`, and `;` in between two commands. Chaining is not supported.
### Background processes
An external command suffixed with a `&` should be run in the background, and the shell should be ready to take the next command before the first command has finished running.
### `ps`
Behaves just like `ps` described in the POSIX manual. It should print the following:
1. PID: Process ID
2. NLWP: Number of threads current being used
3. VSZ: Program size (virtual memory size) in KB
4. STAT: State of the process
5. START: Start time of the process
6. TIME: Amount of CPU time that the process has been executing
7. COMMAND: The command that executed the process
### Redirection operators
Supports `>>`, `>`, and `<` Chaining is not supported.
### Signal commands
1. `kill <pid>` behaves normally, sends `SIGKILL` to the specified process.
2. `stop <pid>` stops a currently executing process by sending `SIGSTOP`.
3. `cont <pid>` continues a specified process by sending `SIGCONT`.
