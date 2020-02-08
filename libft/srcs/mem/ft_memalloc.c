
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *pocket;

	if (!(pocket = malloc(size)))
		return (NULL);
	ft_bzero(pocket, size);
	return (pocket);
}
