/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:19:22 by rcross            #+#    #+#             */
/*   Updated: 2019/10/23 23:41:49 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		get_ants(t_antfarm *farm, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (0);
		i++;
	}
	farm->antcount = ft_atoi(line);
	return (1);
}

static int		get_node(t_antfarm *farm, char *line)
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

static int		get_in(t_antfarm *farm, int fd)
{
	int		x;
	int		z;
	char	*line;

	z = 1;
	while (z != 0 && (x = get_next_line(fd, &line)) > 0)
	{
		//ft_printf("%s\n", line);
		if (line[0] && line[0] == 'L')
			z = 0;
		else if (line[0] && line[0] == '#')
			z = get_comment(farm, fd, line);
		else if (!farm->antcount)
			z = get_ants(farm, line);
		else if (ft_strchr(line, '-'))
			z = get_arc(farm, line);
		else
			z = get_node(farm, line);
		free(line);
	}
	if (x < 0)
		return (0);
	return (1);
}

int				read_in(t_antfarm *farm, int fd)
{
	int		z;

	if (fd == -1)
		return (0);
	z = get_in(farm, fd);
	if (z == 0
		|| farm->source == NULL
		|| farm->sink == NULL
		|| farm->antcount == 0
		|| farm->nodecount == 0
		|| farm->arccount == 0)
		return (0);
	return (1);
}
