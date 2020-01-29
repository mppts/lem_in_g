#include <lem_in.h>

void		push_back(t_map *g, t_room *room, t_deq *sdeq)
{
	sdeq->rear++;
	sdeq->deq[sdeq->rear] = room;
}

t_room		*pop_front(t_map *g, t_deq *sdeq)
{
	if (sdeq->begin > - 1 && sdeq->begin <= g->num_nodes)
	{
		(sdeq->begin)++;
		return (sdeq->deq[sdeq->begin] - 1);
	}
	else
		return (NULL);
}

t_room		*pop_rear(t_map *g, t_deq *sdeq)
{
	if (sdeq->rear > - 1)
	{
		(sdeq->rear)--;
		return (sdeq->deq[sdeq->rear + 1]);
	}
	else
		return (NULL);
}

void		init_dequeue(t_map *g, t_deq *sdeq)
{
	uint64_t k;

	k = 0;
	while (k < g->num_nodes)
		sdeq->deq[k++] = NULL;
	sdeq->rear = -1;
	sdeq->begin = 0;
}