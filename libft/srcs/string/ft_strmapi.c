
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	szt;
	char	*new;

	if (!s || !f)
		return (NULL);
	szt = 0;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[szt] != '\0')
	{
		new[szt] = f(szt, s[szt]);
		szt++;
	}
	return (new);
}
