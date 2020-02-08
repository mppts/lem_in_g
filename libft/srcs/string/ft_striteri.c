
#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	bogey;

	if (s && f)
	{
		bogey = 0;
		while (s[bogey] != '\0')
		{
			f(bogey, &s[bogey]);
			bogey++;
		}
	}
}
