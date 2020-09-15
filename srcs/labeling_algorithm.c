/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 21:18:34 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/14 23:47:25 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		in_lem_queue(t_queue *q, int node)
{
	t_nodelink *r;

	r = q->first;
	while (r)
	{
		if (r->nodeptr->index == node)
			return (1);
		r = r->next;
	}
	return (0);
}

void	pred_reset(t_antfarm *farm)
{
	ft_memset(farm->pred, -1, farm->nodecount);
	farm->pred[farm->sink->index] = -2;
}

void	labeling_algorithm(t_antfarm *farm)
{
	t_queue 	list;
	int			node_i;
	t_nodelink	*ptr;
	int *labels; // Unlabeled is 0, labeled is 1

	labels = ft_memalloc(sizeof(int) * farm->nodecount); //Init to all unlabeled
	labels[farm->sink->index] = 1; // Label node t
	list.first = 0;
	list.last = 0;
	while (labels[farm->sink->index]) // while t is labeled
	{
		ft_bzero(labels, farm->nodecount * 4); // Unlabel all nodes
		pred_reset(farm);
		labels[farm->source->index] = 1; //label node s
		enqueue_lem(&list, farm->source); //add s to list
		while (list.first || !labels[farm->sink->index]) // list or t is unlabeled
		{
			node_i = dequeue_lem(&list); //Remove a node i from list
			ptr = farm->n_array[node_i]->neighbors->first; //node neighbor
			while (ptr) //for each node in the neighbors queue
			{
				if (!ptr->nodeptr->occupied && !labels[ptr->nodeptr->index])
				{
					farm->pred[ptr->nodeptr->index] = node_i;
					labels[ptr->nodeptr->index] = 1;
					enqueue_lem(&list, ptr->nodeptr);
				}
				ptr = ptr->next;
			}
			if (labels[farm->sink->index])
				add_path(farm, node_i);
		}
	}
}
