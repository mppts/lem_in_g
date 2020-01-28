#include <lem_in.h>

void		push_back(t_map *g, t_room *room, t_room *queue[g->num_nodes], int64_t *rear)
{
	rear++;
	queue[*rear] = room;
}

t_room		*pop_front(t_map *g, t_room *queue[g->num_nodes], int64_t *begin)
{
	if (*begin > - 1)
	{
		(*begin)++;
		return (queue[*begin - 1]);
	}
	else
		return (NULL);
}

t_room		*pop_rear(t_map *g, t_room *queue[g->num_nodes], int64_t *rear)
{
	if (*rear > - 1)
	{
		(*rear)--;
		return (queue[*rear + 1]);
	}
	else
		return (NULL);
}

void		init_queue(t_map *g, t_room	*queue[g->num_nodes])
{
	uint64_t k;

	k = 0;
	while (k < g->num_nodes)
		queue[k++] = NULL;
}


void	dfs(t_map *g, t_room *start, t_queue *q[g->num_nodes], int64_t levs[g->num_nodes])
{
	t_room	*queue[g->num_nodes];
	int64_t rear;
	int64_t lev;
	t_room	*tmp;

	rear = -1;
	init_queue(g, queue);
	push_back(g, start, queue, &rear);
	g->fin->level = INT64_MAX - 10;
	while(-1 != rear)
	{
		tmp = pop_rear(g, queue, &rear);
		tmp = tmp->linked_to->to;
		while (tmp)
		{
			if (levs[tmp->hash_id] == -1)
			{
				push_back(g, tmp, queue, &rear);
			}
			tmp = tmp->next;
		}
	}
	return (queue[rear] == g->fin);
}


int		bfs(t_map *g, t_room *start, t_room *q[g->num_nodes], int64_t levs[g->num_nodes])
{
	t_room	*queue[g->num_nodes];
	int64_t begin;
	int64_t rear;
	int64_t lev;
	t_room	*tmp;
	t_link	*link;

	lev = 0;
	begin = 0;
	rear = -1;
	init_queue(g, queue);
	push_back(g, start, queue, &rear);
	levs[start->hash_id] = lev;
	g->fin->level = INT64_MAX - 10;
	while(begin != rear)
	{
		tmp = pop_front(g, queue, &begin);
		lev = levs[tmp->hash_id] + 1;
		link = tmp->linked_to;
		while (link)
		{
			if (link->path_id)
				continue ;
			if (levs[link->to->hash_id] == -1)
			{
				levs[link->to->hash_id]= lev;
				push_back(g, link->to, queue, &rear);
			}
			link = link->next;
		}
	}
	return (queue[rear] == g->fin);
}

void			dinic(t_map *g, int ants)
{
	t_room		*q[g->num_nodes];
	int64_t		lev[g->num_nodes];
	uint64_t 	n;

	n = 0;
	while (n < g->num_nodes)
		lev[n++] = -1;
	//if bfs is NULL return paths else search path
	bfs(g, g->start, q, lev);


}


//dinic algorithm and Edmonds-Karp algorithm

