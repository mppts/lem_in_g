
#include "libft.h"

void		ft_strclr(char *s)
{
	if (s)
		ft_bzero((void *)s, ft_strlen(s));
}
