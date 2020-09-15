/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:15:45 by rcross            #+#    #+#             */
/*   Updated: 2019/10/16 19:41:14 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			add_node_to_lst(t_antfarm *farm, char **tab, int z)
{
	t_adjlst	*t;

	t = init_adjlst();
	t->a_i = init_node();
	t->next = farm->graph;
	t->a_i->name = ft_strdup(tab[0]);
	t->a_i->coord_x = ft_atoi(tab[1]);
	t->a_i->coord_y = ft_atoi(tab[2]);
	if (z == 1)
		farm->source = t->a_i;
	else if (z == 2)
		farm->sink = t->a_i;
	farm->graph = t;
}
