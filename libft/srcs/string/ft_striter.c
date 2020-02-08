
#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s != '\0')
			f(s++);
}
