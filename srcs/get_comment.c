/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:19:10 by rcross            #+#    #+#             */
/*   Updated: 2019/10/16 18:41:16 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	get_source(t_antfarm *farm, int fd)
{
	int		x;
	char	*line;
	char	**tab;

	if ((x = get_next_line(fd, &line)) > 0)
	{
		//ft_printf("%s\n", line);
		if (valid_node(farm, line))
		{
			tab = ft_strsplit(line, ' ');
			add_node_to_lst(farm, tab, 1);
			farm->nodecount++;
			ft_free_2d(tab);
		}
		else
			x = 0;
		free(line);
	}
	return (x <= 0 ? 0 : 1);
}

static int	get_sink(t_antfarm *farm, int fd)
{
	int		x;
	char	*line;
	char	**tab;

	if ((x = get_next_line(fd, &line)) > 0)
	{
		//ft_printf("%s\n", line);
		if (valid_node(farm, line))
		{
			tab = ft_strsplit(line, ' ');
			add_node_to_lst(farm, tab, 2);
			farm->nodecount++;
			ft_free_2d(tab);
		}
		else
			x = 0;
		free(line);
	}
	return (x <= 0 ? 0 : 1);
}

int			get_comment(t_antfarm *farm, int fd, char *line)
{
	int		z;

	z = 1;
	if (!ft_strcmp(line, "##start"))
		z = farm->source ? 0 : get_source(farm, fd);
	else if (!ft_strcmp(line, "##end"))
		z = farm->sink ? 0 : get_sink(farm, fd);
	return (z);
}
