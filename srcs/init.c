/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:19:27 by rcross            #+#    #+#             */
/*   Updated: 2019/10/17 16:13:14 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_nodelink	*init_nodelink(void)
{
	t_nodelink	*t;

	t = malloc(sizeof(t_nodelink));
	t->nodeptr = NULL;
	t->next = NULL;
	return (t);
}

t_queue		*init_queue(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

t_node		*init_node(void)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	n->name = NULL;
	n->coord_x = -1;
	n->coord_y = -1;
	n->dist = -1;
	n->occupied = 0;
	n->index = -1;
	n->neighbors = NULL;
	return (n);
}

t_adjlst	*init_adjlst(void)
{
	t_adjlst	*l;

	l = malloc(sizeof(t_adjlst));
	l->next = NULL;
	l->a_i = NULL;
	return (l);
}

t_antfarm	*init_farm(void)
{
	t_antfarm	*farm;

	farm = malloc(sizeof(t_antfarm));
	farm->antcount = 0;
	farm->nodecount = 0;
	farm->arccount = 0;
	farm->source = NULL;
	farm->sink = NULL;
	farm->graph = NULL;
	farm->pred = NULL;
	farm->n_array = NULL;
	farm->paths = malloc(sizeof(t_pq));
	farm->paths->first = NULL;
	farm->paths->last = NULL;
	return (farm);
}
