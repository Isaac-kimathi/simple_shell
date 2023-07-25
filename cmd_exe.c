#include "smain.h"

/**
 * cmd_exe - executes command keyed in on the prompt
 * @argv: agrument vector
 * Return: void
 */
void cmd_exe(char **argv)
{
	char *cmd = NULL, *cmd_real = NULL;

	if (argv)
	{
		cmd = argv[0];
		cmd_real = lctn_gts(cmd);

		if (execve(cmd_real, argv, NULL) == -1)
		{
			perror(": not found");
		}
	}
}
