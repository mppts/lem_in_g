
#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*wrd;
	uint8_t	logos;

	logos = (uint8_t)c;
	if (n == 0)
		return (NULL);
	wrd = (uint8_t*)ft_memchr(src, logos, n);
	if (!wrd)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	else
		return (ft_memcpy(dst, src, (wrd - src) + 1) + (wrd - src) + 1);
}
