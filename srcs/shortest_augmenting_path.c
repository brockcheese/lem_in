/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_augmenting_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:23:55 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/23 16:46:34 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	top_enq(t_queue *path, t_node *content)
{
	t_nodelink	*new;
	
	new = malloc(sizeof(t_nodelink));
	new->nodeptr = content;
	new->next = path->first;
	path->first = new;
	if (!path->last)
		path->last = path->first;
}

void	advance(t_node **node, int *i, int *pred, int node_j)
{
	pred[node_j] = *i;
	node[node_j]->occupied = 1;
	*i = node_j;
}

void	retreat(t_node **n_array, int *i, int *pred, t_node *sink)
{
	int 		min;
	t_nodelink	*tmp;

	tmp = n_array[*i]->neighbors->first;
	min = tmp->nodeptr->dist;
	while (tmp)
	{
		if (min > tmp->nodeptr->dist && pred[tmp->nodeptr->index])
			min = tmp->nodeptr->dist;
		tmp = tmp->next;
	}
	n_array[*i]->dist = min + 1;
	n_array[*i]->occupied = 0;
	if (*i != sink->index)
		*i = pred[*i];
}

void    sap(t_antfarm *farm)
{
	int i;
	int	phasepoint;
	int node_j;

	initsap(farm);
	phasepoint = calc_shiftpoint(farm->nodecount, farm->arccount);	
	i = farm->source->index;
	while (farm->source->dist < phasepoint)
	{
		
		if ((node_j = get_adm_arc(i, farm->n_array)) != -1)
		{
			
			advance(farm->n_array, &i, farm->pred, node_j);
			
			if (i == farm->sink->index)
			{
				add_path(farm, i);
				i = farm->source->index;
				pred_reset(farm);
			}
		}
		else
		{
			
			retreat(farm->n_array, &i, farm->pred, farm->sink);
		}
		
	}
}
