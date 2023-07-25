#include "smain.h"

/*
 * main - shell main function
 *
 * @argc - arguments count parameter
 * @argv - arguments vector parameter
 * Return: 0 if successful
 */
int main(int agrc, char **argv)
{
	const char *delim = " \n";
	char *token;
	char *prompt = "(KimSshell) $ ";
	int tkn_no = 0;
	char *ptrcmd = NULL, *ptrcmd_copy = NULL;
	ssize_t rd_chrs;
	int x;
	size_t y = 0;

	(void)agrc;
	while (1)
	{
		printf("%s", prompt);
		rd_chrs = getline(&ptrcmd, &y, stdin);
		if (rd_chrs == -1)
		{
			printf("Exiting sshell\n");
			return (-1);
		}
		ptrcmd_copy = malloc(sizeof(char) * rd_chrs);
		if (ptrcmd_copy == NULL)
		{
			perror("error on memory allocation error");
			return (-1);
		}
		strcpy(ptrcmd_copy, ptrcmd);

		token = strtok(ptrcmd, delim);
		while (token)
		{
			tkn_no++;
			token = strtok(NULL, delim);
		}
		tkn_no++;

		argv = malloc(sizeof(char *) * tkn_no);
		token = strtok(ptrcmd_copy, delim);

		for (x = 0; token != NULL ; x++)
		{
			argv[x] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[x], token);
			token = strtok(NULL, delim);
		}
		argv[x] = NULL;
		cmd_exe(argv);
	}
	free(ptrcmd_copy);
	free(ptrcmd);

	return (0);
}
