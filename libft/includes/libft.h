/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:02:42 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/17 17:18:03 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>

// # define DEBst() printf("\t\033[0;31m%d\033[0m in:\t%s \t\t", __LINE__, __func__);
// # define DEBend() printf("\n");
// # define DEBit(name, x) printf("\033[1;35m%s\033[0m == %p ", (name), (x));
// # define DEBintt(name, x) printf("\033[1;35m%s\033[0m == %d ", (name), (x));
// # define DEBlt(name, x) printf("\033[1;35m%s\033[0m == %zu ", (name), (x));
// # define DEBtextt(name, x) printf("[\033[1;35m%s\033[0m] == [%s] ", (name), (x));
// # define DEBchart(name, x) printf("[\033[1;35m%s\033[0m] == [%c] ", (name), (x));
// # define DEBmesst(name) printf("\033[1;36m%s\033[0m ", (name));
// # define DEBfunc() printf("\033[0;33mEntering\033[0m MY:\t\033[0;33m%s\033[0m of file \"%s\"\n", __func__, __FILE__);
// # define DEB() printf("\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__);
// # define DEBex(name) printf("\033[0;32mExiting \033[0m MY:\t\033[0;32m%s\033[0m,%s\n\n", __func__, (name));
// # define DEBprog() printf("\n\nENTRANCE IN \033[0;33m~~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~\033[0m\n", __FILE__);
// # define DEBm() printf("Malloc failed at line \033[0;31m%d\033[0m in function: %s\n", __LINE__, __func__);
// # define DEBi(name, x) printf("\033[0;31m%d\033[0m str in func: %s, \"\033[1;35m%s\033[0m\" adress %p\n", __LINE__, __func__, (name), (x));
// # define DEBtext(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s] == [%s]\n", __LINE__, __func__, (name), (x));
// # define DEBpar(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s]:\n[\n%s\n]\n", __LINE__, __func__, (name), (x));
// # define DEBl(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %zu\n", __LINE__, __func__, (name), (x));
// # define DEBint(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %d\n", __LINE__, __func__, (name), (x));

# define DEBst() {}
# define DEBend() {}
# define DEBit(name, x) {}
# define DEBintt(name, x) {}
# define DEBlt(name, x) {}
# define DEBtextt(name, x) {}
# define DEBchart(name, x) {}
# define DEBmesst(name) {}
# define DEBfunc() {}
# define DEB() {}
# define DEBex(name) {}
# define DEBprog() {}
# define DEBm() {}
# define DEBi(name, x) {}
# define DEBtext(name, x) {}
# define DEBpar(name, x) {}
# define DEBl(name, x) {}
# define DEBint(name, x) {}


/*
** libFT defines
*/

# define ULL unsigned long long
# define UCC unsigned const char
# define CC const char
# define UC unsigned char
# define CV const void
# define SST signed size_t
# define MHZERO 0x0101010101010101UL
# define DHZERO 0x8080808080808080UL

/*
** GNL defines
*/

# define BUFF_SIZE 128
# define B_S BUFF_SIZE
# define FDRSET &fdl, fd, fdl, fdl
# define RSSET line, pl[0], &fdl
# define SIZEOFSBSTR bgy[0] - rem->CNT - 1 - SZFINT
# define content_size C_S
# define content CNT
# define SZFSZT sizeof(size_t)
# define SZFINT sizeof(int)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Function prototypes taken in Mojave MacOS version (variable names slightly
** vary from version to version..
*/


void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strnlen(const char *str, size_t maxlen);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
									size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
size_t				ft_strchrcount(const char *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_del(void *content, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long long			ft_atoli(const char *str);
int					get_next_line(const int fd, char** line);


#endif
