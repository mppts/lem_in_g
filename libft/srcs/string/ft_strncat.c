
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ps1;

	ps1 = s1;
	while (*s1)
		++s1;
	while ((*s1 = *s2++) && n--)
		++s1;
	*s1 = 0;
	return (ps1);
}
