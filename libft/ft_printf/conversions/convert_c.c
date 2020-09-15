/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:30 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:56 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

void		convert_c(t_printf *data)
{
	char		c;

	c = (char)va_arg(data->ap, int);
	if (data->flag[3] == '0' && data->flag[0] != '-')
		padding(data, '0', data->field_width - 1, 1);
	else if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - 1, 1);
	write(1, &c, 1);
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - 1, 1);
}
