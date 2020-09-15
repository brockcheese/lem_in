/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:00:43 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:39 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		parse_flags(t_printf *data)
{
	int		i;

	i = -1;
	while (data->flag_mask[++i] != '\0')
	{
		while (data->flag_mask[i] == data->format2[data->i])
		{
			while (data->format2[data->i] == '-' && data->i++)
				data->flag[0] = '-';
			while (data->format2[data->i] == '+' && data->i++)
				data->flag[1] = '+';
			while (data->format2[data->i] == ' ' && data->i++)
				data->flag[2] = ' ';
			while (data->format2[data->i] == '0' && data->i++)
				data->flag[3] = '0';
			while (data->format2[data->i] == '#' && data->i++)
				data->flag[4] = '#';
			i = 0;
		}
	}
}

void		parse_field_width(t_printf *data)
{
	if (data->format2[data->i] == '*')
	{
		data->field_width = va_arg(data->ap, int);
		data->i++;
		return ;
	}
	while (data->format2[data->i] >= '0' && data->format2[data->i] <= '9')
	{
		data->field_width *= 10;
		data->field_width += (data->format2[data->i] - 48);
		data->i++;
	}
}

void		parse_precision(t_printf *data)
{
	while (data->format2[data->i] == '.')
	{
		data->i++;
		data->precision = 0;
		if (data->format2[data->i] == '*')
		{
			data->precision = va_arg(data->ap, int);
			data->i++;
			return ;
		}
		while (data->format2[data->i] >= '0' && data->format2[data->i] <= '9')
		{
			data->precision *= 10;
			data->precision += (data->format2[data->i] - 48);
			data->i++;
		}
	}
}

void		parse_length(t_printf *data)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (data->length_mask[++i] != '\0')
	{
		while (data->length_mask[i] == data->format2[data->i])
		{
			data->length[j] = data->format2[data->i];
			data->length[j + 1] = '\0';
			data->i++;
			j++;
		}
	}
}

void		parse_conversion(t_printf *data)
{
	int		i;

	i = -1;
	while (data->conversion_mask[++i] != '\0')
	{
		if (data->conversion_mask[i] == data->format2[data->i])
		{
			data->conversion = data->conversion_mask[i];
			return ;
		}
	}
}
