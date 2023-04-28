#include "main.h"
/**
 * _myexit - exits the shell
 * @info: Structure
 * Return: exits with a given exit status
 */
int _myexit(info_t *info)
{
	int exitcode = 0;

	if (info->argv[1])
	{
		exitcode = atoi(info->argv[1]);
		if (exitcode == 0 && strcmp(info->argv[1], "0") != 0)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
	}
	exit(exitcode);
}
/**
 * _mycd - changes the current directory of the process
 * @info: Structure
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir = NULL;
	char buffer[1024];

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME");
		if (!dir)
			dir = "/";
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD");
		if (!dir)
		{
			_puts("bash: cd: OLDPWD not set\n");
			return (1);
		}
		_puts(_getenv(info, "OLDPWD")), _putchar('\n');
	}
	else
		dir = info->argv[1];
	if (chdir(dir) == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(dir), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", getenv("PWD"), 1);
		_setenv(info, "PWD", getcwd(buffer, 1024), 1);
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
