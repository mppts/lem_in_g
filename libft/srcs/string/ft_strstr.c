
#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*camel;
	const char	*eye;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		camel = haystack;
		eye = needle;
		while (*eye != '\0' && *camel == *eye)
		{
			++eye;
			++camel;
		}
		if (*eye == '\0')
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
