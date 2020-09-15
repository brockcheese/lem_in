/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:56:52 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/18 03:20:52 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	clear_distance(t_node **n_array, int nodecount)
{
	int i;

	i = 0;
	while (i < nodecount)
		n_array[i++]->dist = -1;
}

int		dequeue_lem(t_queue *q)
{
	t_nodelink	*tmp;
	int			node_index;

	if (!q->first)
		return (0);
	tmp = q->first;
	node_index = tmp->nodeptr->index;
	q->first = tmp->next;
	if (!q->first)
		q->last = 0;
	free(tmp);
	return (node_index);
}

void	enqueue_lem(t_queue *q, t_node *nodeptr)
{
	t_nodelink *new;
	t_nodelink *last;

	new = malloc(sizeof(t_nodelink));
	new->nodeptr = nodeptr;
	new->next = 0;
	if (!q->first)
		q->first = new;
	if (q->last)
	{
		last = q->last;
		last->next = new;
	}
	q->last = new;
}

/*
** https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/

void	init_distance_labels(t_antfarm *farm)
{
	t_queue		q;
	int			v;
	t_nodelink	*w;

	clear_distance(farm->n_array, farm->nodecount);
	farm->sink->dist = 0;
	// BREADTH FIRST SEARCH
	q.first = 0;
	q.last = 0;
	enqueue_lem(&q, farm->sink);
	farm->sink->dist = 0;
	printf("\n\n\n\n\n\t%i: %i\n", farm->sink->index, farm->sink->dist);
	while (q.first)
	{
		v = dequeue_lem(&q);
		w = farm->n_array[v]->neighbors->first;
		while (w)
		{
			if (w->nodeptr->dist == -1)
			{
				enqueue_lem(&q, w->nodeptr);
				w->nodeptr->dist = farm->n_array[v]->dist + 1;
				printf("\t%i: %i\n", w->nodeptr->index, w->nodeptr->dist);
			}
			w = w->next;
		}
	}
}
