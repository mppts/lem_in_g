
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*bogey;

	if (!s || !f)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	bogey = new;
	while (*s != '\0')
		*bogey++ = f(*s++);
	return (new);
}
