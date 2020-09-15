/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sap_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:21:48 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/23 16:45:33 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_adm_arc(int i, t_node **n_array)
{
	t_nodelink	*ptr;

	ptr = n_array[i]->neighbors->first;
	while (ptr)
	{
		if (!ptr->nodeptr->occupied)
			if (n_array[i]->dist == ptr->nodeptr->dist + 1)
				return (ptr->nodeptr->index);
		ptr = ptr->next;
	}
	return (-1);
}

void	zero_flows(int *pred, int nodecount)
{
	int i;

	i = -1;
	while (++i < nodecount)
		pred[i] = -1;
}

void	initsap(t_antfarm *farm)
{
	int i;

	farm->pred = ft_memalloc(4 * farm->nodecount);
	i = -1;
	while (++i < farm->nodecount)
		farm->pred[i] = -1;
	farm->pred[farm->sink->index] = -2;
	init_distance_labels(farm); //Reverse breadth first search
}

void	path_fill(t_antfarm *farm, t_pathhead *p, int i)
{
	p->length = 0;
	while (i != farm->source->index)
	{
		top_enq(p->path, farm->n_array[i]);
		i = farm->pred[i];
		p->length++;
	}
}

void	enqueue_ph(t_pq *paths, t_pathhead *pathhead)
{
	t_pathhead *tmp;

	pathhead->next = 0;
	if (!paths->first)
		paths->first = pathhead;
	if (paths->last)
	{
		tmp = paths->last;
		tmp->next = pathhead;
	}
	paths->last = pathhead;
}

void	add_path(t_antfarm *farm, int i)
{
	t_pathhead *p;

	p = malloc(sizeof(t_pathhead));
	p->next = 0;
	p->path = malloc(sizeof(t_queue));
	p->length = 0;
	p->min_ants = 0;
	path_fill(farm, p, i);
	enqueue_ph(farm->paths, p);
}
