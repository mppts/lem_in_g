
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sub;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		sub = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = sub;
	}
	*alst = NULL;
}
