/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_islowercase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:23:00 by rcross            #+#    #+#             */
/*   Updated: 2019/03/03 15:47:30 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_islowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!ft_islowercase(str[i++]))
			return (0);
	return (1);
}
