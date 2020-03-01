#ifndef LEM_IN_PUT_H
# define LEM_IN_PUT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_mem.h"
# include "ft_string.h"

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);


#endif
