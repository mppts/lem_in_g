
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*n;
	char	*p;

	n = ft_strchr(s, c);
	p = n;
	while (p)
	{
		n = p;
		p = ft_strchr(n + 1, c);
	}
	return (n);
}
