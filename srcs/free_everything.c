/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:15:31 by rcross            #+#    #+#             */
/*   Updated: 2019/10/16 15:36:36 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	free_queue(t_queue *q)
{
	t_nodelink	*t;

	while (q && q->first)
	{
		t = q->first;
		q->first = q->first->next;
		t ? free(t) : 0;
	}
	q ? free(q) : 0;
}

static void	free_pq(t_pq *q)
{
	t_pathhead	*t;

	while (q && q->first)
	{
		t = q->first;
		q->first = q->first->next;
		t ? free(t) : 0;
	}
	q ? free(q) : 0;
}

static void	free_adjlst(t_adjlst *g)
{
	t_adjlst	*t;

	while (g)
	{
		t = g;
		g->a_i->name ? free(g->a_i->name) : 0;
		g->a_i->neighbors ? free_queue(g->a_i->neighbors) : 0;
		g->a_i ? free(g->a_i) : 0;
		g = g->next;
		t ? free(t) : 0;
	}
}

void		free_everything(t_antfarm *farm, int succ)
{
	succ ? 0 : ft_printf("ERROR\n");
	farm->graph ? free_adjlst(farm->graph) : 0;
	farm->paths ? free_pq(farm->paths) : 0;
	farm->pred ? free(farm->pred) : 0;
	farm->n_array ? free(farm->n_array) : 0;
	farm ? free(farm) : 0;
	//system("leaks a.out");//--------------------------------------------
	exit(0);
}
