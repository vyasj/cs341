#ifndef SHELL_H_
#define SHELL_H_

// Start the shell, provide either valid flag, or an empty string for no flag.
void load_file(char *flag, char *filename);

// Print the prompt line and wait for user input.
void prompt_input();

#endif
