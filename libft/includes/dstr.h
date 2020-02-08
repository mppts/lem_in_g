
#ifndef LEM_IN_DSTR_H
#define LEM_IN_DSTR_H

# include <stdlib.h>
# include <inttypes.h>
# include "libft.h"

typedef struct		s_dstr
{
	char			*data;
	uint64_t		len;
	uint64_t		cap;
}					t_dstr;

void				dstr_del(t_dstr *str);
t_dstr				*dstr_init(char *data, uint64_t cap);
t_dstr				*dstr_joinstr(t_dstr *dstr, char *s);

#endif