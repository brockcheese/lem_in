/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:04:30 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/23 16:46:09 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "../libft/libft.h"

typedef struct			s_nodelink
{
	struct s_node		*nodeptr;
	struct s_nodelink	*next;
}						t_nodelink;

typedef struct		s_queue
{
	t_nodelink		*first;
	t_nodelink		*last;
}					t_queue;


typedef struct		s_node
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				dist;
	int				occupied;
	int				index;
	t_queue			*neighbors;
}					t_node;

typedef struct		s_adjlst
{
	struct s_adjlst	*next;
	struct s_node	*a_i;
}					t_adjlst;

//Use linked list to hold the set of all paths
typedef	struct			s_pathhead
{
	struct s_pathhead	*next;
	t_queue				*path;
	int					length;
	// The minimum number of ants to keep sending down that path
	// min_ants = next->min_ants + length(B) - length(A) + 1
	int					min_ants;
	//queue points to nlinks
}						t_pathhead;

typedef struct		s_pq
{
	t_pathhead		*first;
	t_pathhead		*last;
}					t_pq;

typedef struct		s_antfarm
{
	int				antcount;
	int				nodecount;
	int				arccount;
	t_node			*source;
	t_node			*sink;
	t_adjlst		*graph;
	t_node			**n_array;
	int				*pred;
	t_pq			*paths;
	//Array of pointers to t_nodes, set all to node_arr[SOURCE] to begin
}					t_antfarm;


/////////////////////////////////////////////
/////////        PROTOTYPES         /////////
/////////////////////////////////////////////

//// QUEUING

int		dequeue_lem(t_queue *q);
void	enqueue_lem(t_queue *q, t_node *nodeptr);

//// SHORTEST AUGMENTING PATH

int		calc_shiftpoint(int n, int m);
void	zero_flows(int *pred, int nodecount);
int		get_adm_arc(int i, t_node **node_arr);
void	init_sap(t_antfarm *farm);
void	add_path(t_antfarm *farm, int i);

void	sap(t_antfarm *farm);
void	advance(t_node **node, int *i, int *pred, int node_j);
void	retreat(t_node **node_arr, int *i, int *pred, t_node *sink);
void	init_distance_labels(t_antfarm *farm);
void	initsap(t_antfarm *farm);
void	pred_reset(t_antfarm *farm);

//// LABELING ALGORITHM

void	labeling_algorithm(t_antfarm *farm);

//// PARSING

t_antfarm	*init_farm(void);
t_adjlst	*init_adjlst(void);
t_node		*init_node(void);
t_queue		*init_queue(void);
t_nodelink	*init_nodelink(void);
int			read_in(t_antfarm *farm, int fd);
int			get_comment(t_antfarm *farm, int fd, char *line);
int			valid_arc(t_antfarm *farm, char *line);
int			valid_node(t_antfarm *farm, char *line);
void		add_node_to_lst(t_antfarm *farm, char **tab, int z);
int			get_arc(t_antfarm *farm, char *line);
void		top_enq(t_queue *path, t_node *content);

////

void		free_everything(t_antfarm *farm, int error);

#endif
