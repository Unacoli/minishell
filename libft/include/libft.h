/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:38:36 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 12:51:47 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include "get_next_line.h"

struct	s_list
{
	void			*content;
	struct s_list	*next;
};

typedef struct s_list	t_list;

int		ft_strlen(char const *str);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isspace(char c);
int		ft_isinbase(char c, char *base);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
long	ft_atoi(const char *str);
int		ft_check_base(const char *base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi_base(const char *str, char *base);
int		ft_lstsize(t_list *lst);
int		ft_int_error(int ac, char **av);

char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
char	*ft_itoa_base(int nb, const char *base);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_convert_base(const char *nbr, char *b_from, char *b_to);

void	ft_quit(char *message);
void	ft_putnbr(int n);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	ft_lstadd_front(t_list **alst, t_list *new_list);
void	ft_lstadd_back(t_list **alst, t_list *new_list);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_print_str_tab(char **tab);
void	ft_free_tab(void ***tab);

size_t	ft_strlcat(char *dst, char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
