#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include <stdlib.h>
# include <string.h>

typedef struct		s_string
{
	char			*str;
	size_t			len;
	struct s_string	*next;
}					t_string;

#endif