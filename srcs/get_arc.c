/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:17:56 by rcross            #+#    #+#             */
/*   Updated: 2019/10/08 16:17:56 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		enqueue_neighbor(t_queue *neighbors, t_node *n)
{
	t_nodelink	*t;

	t = init_nodelink();
	t->nodeptr = n;
	if (!neighbors->first)
		neighbors->first = t;
	else
		neighbors->last->next = t;
	neighbors->last = t;
}

static t_node	*find_node(t_antfarm *farm, char *name)
{
	t_adjlst	*t;
	t_node		*r;

	if (farm->source && farm->source->name
		&& !ft_strcmp(farm->source->name, name))
		return (farm->source);
	else if (farm->sink && farm->sink->name
		&& !ft_strcmp(farm->sink->name, name))
		return (farm->sink);
	t = farm->graph;
	r = NULL;
	while (t)
	{
		if (!ft_strcmp(t->a_i->name, name))
		{
			r = t->a_i;
			break ;
		}
		t = t->next;
	}
	return (r);
}

static int		unique_neighbor(t_queue *neighbors, t_node *n)
{
	t_nodelink	*t;

	t = neighbors->first;
	while (t)
	{
		if (t->nodeptr == n)
			return (0);
		t = t->next;
	}
	return (1);
}

static int		update_neighbors(t_antfarm *farm, char *name, char *name2)
{
	t_node		*n;
	t_node		*n2;

	n = find_node(farm, name);
	n2 = find_node(farm, name2);
	if (n == n2)
		return (0);
	if (!n->neighbors)
		n->neighbors = init_queue();
	else if (!unique_neighbor(n->neighbors, n2))
		return (0);
	enqueue_neighbor(n->neighbors, n2);
	if (!n2->neighbors)
		n2->neighbors = init_queue();
	else if (!unique_neighbor(n2->neighbors, n))
		return (0);
	enqueue_neighbor(n2->neighbors, n);
	return (1);
}

int				get_arc(t_antfarm *farm, char *line)
{
	int		z;
	char	**tab;

	z = 1;
	if (valid_arc(farm, line))
	{
		tab = ft_strsplit(line, '-');
		z = update_neighbors(farm, tab[0], tab[1]);
		z == 1 ? farm->arccount++ : 0;
		ft_free_2d(tab);
	}
	else
		z = 0;
	return (z);
}
