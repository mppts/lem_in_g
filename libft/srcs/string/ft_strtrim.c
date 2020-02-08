
#include "libft.h"

char			*ft_strtrim(char const *s)
{
	const char	*bogey;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	bogey = s + ft_strlen(s) - 1;
	while (*bogey == ' ' || *bogey == '\t' || *bogey == '\n')
		bogey--;
	return (ft_strsub(s, 0, bogey - s + 1));
}
