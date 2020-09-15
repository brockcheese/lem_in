/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:18:56 by rcross            #+#    #+#             */
/*   Updated: 2019/10/08 16:18:57 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				get_node(t_antfarm *farm, char *line)
{
	int		z;
	char	**tab;

	z = 1;
	if (valid_node(farm, line))
	{
		tab = ft_strsplit(line, ' ');
		add_node_to_lst(farm, tab, 0);
		farm->nodecount++;
		ft_free_2d(tab);
	}
	else
		z = 0;
	return (z);
}
