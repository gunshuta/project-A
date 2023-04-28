#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#define CONVERT_UNSIGNED 2

/**
 * struct liststr - singly linked list
*
* num: the number field
*
* @str: a string
*
* @next: points to the next node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
	const char *head;
} list_t;
typedef struct infot
{
	int argc;
	char *arg;
	char **argv;
	int status;
	char *history;
	char *alias;
	char **environ;
	char *fname;
	int line_count;
	char *buffer;
	int buffer_type;
	char *path;
	char **cmd_buf;
	list_t *env;
	int readfd;
	int histcount;
}info_t;
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;
int _interactive(char *s);
int is_interactive(info_t *info);
int is_delimiter(char c);
int has_alphabets(char *s);


int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *subs);
char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

size_t listLen(const list_t *head);
char **strlist(list_t *head);
size_t print_list(const list_t *head);
list_t *strNode(list_t *head, char *pre, char c);
ssize_t strindexOf(list_t *head, list_t *node);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);


int input_buffer(info_t *info, char **buffer, size_t *x);
int get_input(info_t *info, char **command);
int read_buffer(int fd, char *buffer, size_t *i);
void sigintHandler(__attribute__((unused))int sig_num);

int _strconvert(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);




#endif
