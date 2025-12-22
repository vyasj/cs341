#ifndef SHELL_H_
#define SHELL_H_

// -f flag used, load file and run all commands
void load_file(char *filename);

// -h flag used, output history to file
void write_cmd(char *filename, char* cmd);

// fork-exec-wait cycle
int cycle(char* cmd);

#endif
