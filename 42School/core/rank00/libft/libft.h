
#ifndef LIBFT_H

#define LIBFT_H

// allowed
#include <stdlib.h>
#include <unistd.h>

// test
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// <ctype.h>
int	ft_isdigit(int);
int	ft_isalpha(int);
int	ft_isalnum(int);
int ft_isprint(int);
int	ft_isascii(int);
int	ft_islower(int);
int	ft_isupper(int);
int ft_tolower(int);
int ft_toupper(int);

// <stdlib.h>
int ft_atoi(const char *);
void *ft_calloc(size_t, size_t);

// <strings.h>
void ft_bzero(void *, size_t);

// <string.h>
size_t ft_strlen(const char *);
char *ft_strchr(const char *, int);
char *ft_strrchr(const char *, int);
int ft_strncmp(const char *, const char *, size_t);
char *ft_strnstr(const char *,	const char *, size_t);
size_t ft_strlcpy(char *, const char *restrict,size_t);
size_t ft_strlcat(char *, const char *restrict,size_t);
char *ft_strdup(const char *);
void *ft_memchr(const void *, int, size_t);


void *ft_memset(void *, int, size_t);

#endif