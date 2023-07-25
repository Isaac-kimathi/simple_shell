#include "smain.h"

/**
 * lctn_gts - creates a path for command
 * @cmd: char pointer par
 * return: pointer to pointer
 */
char *lctn_gts(char *cmd)
{
	int lgth_cmd, lgth_dir;
	char *pth, *cpy_pth, *tok_pth, *pth_fl;
	struct stat buf;

	pth = getenv("PATH");

	if (pth)
	{
		cpy_pth = strdup(pth);
		lgth_cmd = strlen(cmd);
		tok_pth = strtok(cpy_pth, ":");

		while (tok_pth)
		{
			lgth_dir = strlen(tok_pth);
			pth_fl = malloc(lgth_cmd + lgth_dir + 2);
			strcpy(pth_fl, tok_pth);
			strcat(pth_fl, "/");
			strcat(pth_fl, cmd);
			strcat(pth_fl, "\0");

			if (stat(pth_fl, &buf) == 0)
			{
				free(cpy_pth);
				return (pth_fl);
			}
			else
			{
				free(pth_fl);
				tok_pth = strtok(NULL, ":");
			}
		}
		free(cpy_pth);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}

	return (NULL);
}
