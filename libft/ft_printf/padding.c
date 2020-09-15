/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:45 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:34 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		padding(t_printf *data, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			data->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

void		padding2(char to_print, int *count, int spaces)
{
	while (spaces-- > 0)
	{
		ft_putchar(to_print);
		*count += 1;
	}
}
