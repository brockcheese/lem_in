/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:18:35 by rcross            #+#    #+#             */
/*   Updated: 2019/10/08 17:36:42 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		check_node(char *tab1, char *tab2)
{
	int		i;
	int		z;

	i = 0;
	z = 1;
	if (!tab1 || !tab2)
		return (0);
	while (tab1[i] && z != 0)
	{
		if (!(tab1[i] >= '0' && tab1[i] <= '9'))
			z = 0;
		i++;
	}
	i = 0;
	while (tab2[i] && z != 0)
	{
		if (!(tab2[i] >= '0' && tab2[i] <= '9'))
			z = 0;
		i++;
	}
	return (z);
}

static int		unique_node(t_antfarm *farm, char *tab0)
{
	t_adjlst	*t;
	int			z;

	t = farm->graph;
	z = 1;
	if ((farm->source && farm->source->name
		&& !ft_strcmp(farm->source->name, tab0))
		|| (farm->sink && farm->sink->name
		&& !ft_strcmp(farm->sink->name, tab0)))
		return (0);
	while (t && z != 0)
	{
		if (t->a_i && t->a_i->name && !(ft_strcmp(tab0, t->a_i->name)))
			z = 0;
		t = t->next;
	}
	return (z);
}

int				valid_node(t_antfarm *farm, char *line)
{
	int		z;
	char	**tab;

	z = 1;
	tab = ft_strsplit(line, ' ');
	if (tab[3])
		z = 0;
	if (z != 0 && !unique_node(farm, tab[0]))
		z = 0;
	if (z != 0 && !check_node(tab[1], tab[2]))
		z = 0;
	ft_free_2d(tab);
	return (z);
}

static int		node_exists(t_antfarm *farm, char *name)
{
	int			z;
	t_adjlst	*t;

	t = farm->graph;
	z = 0;
	if ((farm->source && farm->source->name
		&& !ft_strcmp(farm->source->name, name))
		|| (farm->sink && farm->sink->name
		&& !ft_strcmp(farm->sink->name, name)))
		return (1);
	while (t && z != 1)
	{
		if (t->a_i && t->a_i->name && !ft_strcmp(t->a_i->name, name))
			z = 1;
		t = t->next;
	}
	return (z);
}

int				valid_arc(t_antfarm *farm, char *line)
{
	int		z;
	char	**tab;

	z = 1;
	tab = ft_strsplit(line, '-');
	if (tab[2])
		z = 0;
	if (z != 0 && !ft_strcmp(tab[0], tab[1]))
		z = 0;
	if (z != 0 && !node_exists(farm, tab[0]))
		z = 0;
	if (z != 0 && !node_exists(farm, tab[1]))
		z = 0;
	ft_free_2d(tab);
	return (z);
}
