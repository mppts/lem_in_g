#include <lem_in.h>

void		deq_push_back(void *room, t_deq *sdeq)
{
	if (sdeq->num_elems > sdeq->rear)
	{
		sdeq->rear++;
		sdeq->deq[sdeq->rear * sdeq->size_of_elem]= room;
	}
	else
		ft_putstr("error in adding element to queue");
}

t_room		*deq_pop_front(t_deq *sdeq)
{
	if (sdeq->begin > - 1 && sdeq->begin < sdeq->num_elems)
	{
		(sdeq->begin)++;
		return (sdeq->deq[(sdeq->begin - 1) * sdeq->size_of_elem]);
	}
	else
		return (NULL);
}

void		*deq_pop_rear(t_deq *sdeq)
{
	if (sdeq->rear > - 1)
	{
		(sdeq->rear)--;
		return (sdeq->deq[(sdeq->rear  + 1) * sdeq->size_of_elem]);
	}
	else
		return (NULL);
}

void		deq_remove_unsafe(t_deq *deq)
{
	if (deq)
	{
		if (deq->deq)
			free(deq->deq);
		free(deq);
	}
}

t_deq		*deq_init_malloc(uint64_t num_elems, size_t size_of_elem)
{
	t_deq	*new;

	if (!num_elems || !size_of_elem)
		return (NULL);
	if (!(new = malloc(sizeof(t_deq))))
		return (NULL);
	if (!(new->deq = malloc(sizeof(num_elems * size_of_elem))))
	{
		free(new);
		return (NULL);
	}
	ft_bzero(new->deq, num_elems * size_of_elem);
	new->rear = -1;
	new->begin = 0;
	new->num_elems = num_elems;
	new->size_of_elem = size_of_elem;
	return (new);
}