#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
	const char * cmd = argv[1];

	char ** cmdarg = (char **)malloc(sizeof(char *) * (argc + 2));
	// add -t
	cmdarg[0] = cmd;
	cmdarg[1] = "-t";
       	cmdarg[2] = "TERM=xterm-256color";
	for (int i = 2, j = 3; i < argc; ++i, ++j) {
		cmdarg[j] = (char *)argv[i];
	}
	cmdarg[argc + 1] = 0;

	printf("%s : args : ", cmd);
	for (int i = 0; i < argc + 2; ++i)
		printf("%s ", cmdarg[i]);
	printf("\n");

	int err = execv(cmd, cmdarg);
	return err;
}

