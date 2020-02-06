#include "ft_writer.h"
#include "libft.h"

t_string 		*add_string(t_string *s1, t_string *s2)
{
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ()
}

t_string		*new_string(char *str)
{
	t_string	*new;

	if(str == NULL)
		return (NULL);
	if (!(new = (t_string*)malloc(sizeof(t_string))))
		return (NULL);
	new->str = ft_strlen(str);
	new->str = str;
	new->next = NULL;
}