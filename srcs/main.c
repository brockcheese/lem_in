/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:51:19 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/23 23:42:11 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

// void	send_ants(t_antfarm *farm)
// {

// }

static t_node	**init_n_array(t_antfarm *farm)
{
	t_node		**array;
	t_adjlst	*t;
	int			i;

	array = malloc(sizeof(t_node *) * farm->nodecount);
	t = farm->graph;
	i = 0;
	while (t && t->a_i)
	{
		array[i] = t->a_i;
		array[i]->index = i;
		t = t->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////

void	fullcheck(t_antfarm *farm)
{
	t_nodelink	*tmp;

	printf("nodecount: %i\n", farm->nodecount);
	printf("SOURCE: %s\n", farm->source->name);
	printf("SINK:   %s\n", farm->sink->name);

	for (int i = 0; i < farm->nodecount; i++)
	{
		printf("%i:\t", farm->n_array[i]->index);
		tmp = farm->n_array[i]->neighbors->first;
		while (tmp)
		{
			printf("%i ", tmp->nodeptr->index);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////


int				main(int argc, char **argv)
{
	t_antfarm	*farm;

	farm = init_farm();
	if (read_in(farm, argc > 1 ? open(argv[1], O_RDONLY) : 0))
	{
		farm->n_array = init_n_array(farm);
		//Labeling algorithm to check for
		fullcheck(farm);
		sap(farm);
		labeling_algorithm(farm);
		ft_printf("\n");
		// send_ants(farm);
		free_everything(farm, 1);
	}
	free_everything(farm, 0);
	return (0);
}
