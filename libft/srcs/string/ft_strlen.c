
#include "libft.h"

size_t			ft_strlen(const char *s)
{
	uint64_t	*longword;
	uint8_t		*byte;

	if (!s)
		return (0);
	byte = (uint8_t*)s;
	while ((uint64_t)byte & 7ULL)
	{
		if (*byte == '\0')
			return ((size_t)byte - (size_t)s);
		byte++;
	}
	longword = (uint64_t*)byte;
	while ((((*longword) - MHZERO)
	& ~(*longword) & DHZERO) == FALSE)
		longword++;
	byte = (uint8_t*)longword;
	while (*byte)
		byte++;
	return ((size_t)byte - (size_t)s);
}
