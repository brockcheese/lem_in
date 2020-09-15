/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:18:14 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/10/14 20:24:53 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

double	ft_power(double x, int y)
{
	double	a;
	int		i;

	a = 1;
	i = 0;
	while (++i <= y)
		a *= x;
	return (a);
}

double	ft_nroot(double x, int y)
{
	long double	res;
	long double	root;
	double		precision;

	if (x < 3)
		return ((x < 0) ? 0.0 : x);
	res = 0;
	root = y;
	while ((res = ft_power(root, y)) < x)
	{
		if (res == x)
			return (root);
		root++;
	}
	--root;
	precision = 0.000001;
	while ((res = ft_power(root, y)) <= x)
	{
		if (res == x)
			return (root);
		root += precision;
	}
	return (root - precision);
}

/*
** d(s) >= d* = min{ceiling[2(n^(2/3)), ceiling(m(1/2))]}
*/

int		calc_shiftpoint(int n, int m)
{
	float	n2;
	float	m2;

	n2 = 2 * (ft_nroot(ft_power(n, 2), 3));
	m2 = ft_nroot(m, 2);
	n = (int)n2 + 1;
	m = (int)m2 + 1;
	return ((n < m) ? n : m);
}