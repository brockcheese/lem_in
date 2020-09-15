/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:50:14 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:16:00 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

void		convert_percent(t_printf *data)
{
	if (data->flag[3] == '0' && data->precision <= 0 && !data->flag[0])
	{
		data->precision = data->field_width;
		data->field_width = 0;
	}
	if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - 1, 1);
	if (data->flag[3] == '0')
		padding(data, '0', data->precision - 1, 1);
	write(1, "%", 1);
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - 1, 1);
	data->len++;
}
