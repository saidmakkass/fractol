/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:43:46 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/13 23:43:37 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h> // for uintptr_t
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_format
{
	char			specifier;

	bool			minus;
	bool			zero;
	int				precision;
	int				width;

	bool			hash;
	bool			space;
	bool			plus;

}					t_format;

typedef struct s_printf_data
{
	char			*s;
	t_format		format;
	va_list			args;
	int				written;
	bool			error;

}					t_printf_data;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_atoi(const char *str);
long					ft_atol(const char *str);
char				*ft_itoa(int n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// ft_printf
int					ft_printf(const char *format_str, ...);

int					hex_len(uintptr_t n);
size_t				ft_nbrlen(int n);

void				parser(t_printf_data *data);

void				write_var(t_printf_data *data);
void				write_output(t_printf_data *data, char c);
void				write_padding(t_printf_data *data, char c, int n);
void				write_prefix(t_printf_data *data);

void				ft_putcharf(t_printf_data *data, unsigned char c);
void				ft_putstrf(t_printf_data *data, char *s);
void				ft_putnbrf(t_printf_data *data, int n);
void				ft_putunbrf(t_printf_data *data, unsigned int n);
void				ft_putaddr(t_printf_data *data, void *p);
void				ft_puthex_lower(t_printf_data *data, unsigned int n);
void				ft_puthex_upper(t_printf_data *data, unsigned int n);

#endif
