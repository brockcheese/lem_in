/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:00:37 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:04 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
**	starting values and set masks for later
*/

static void			initialize(t_printf *data, const char *format)
{
	data->format2 = (char *)format;
	data->i = 0;
	data->len = 0;
	data->conversion_mask = "sScdiuoxXpfeEbr%";
	data->flag_mask = "-+ 0#";
	data->length_mask = "lhL";
}

/*
**	reset struct for next conversion
*/

static void			initialize2(t_printf *data)
{
	data->flag[0] = '\0';
	data->flag[1] = '\0';
	data->flag[2] = '\0';
	data->flag[3] = '\0';
	data->flag[4] = '\0';
	data->flag[5] = '\0';
	data->length[0] = '\0';
	data->length[1] = '\0';
	data->length[2] = '\0';
	data->conversion = '\0';
	data->field_width = 0;
	data->precision = -1;
}

static void			print_format(t_printf *data, int count)
{
	char	*format;

	format = NULL;
	if (!count || count < 0)
		return ;
	if (!(format = ft_strndup((data->format2 + (data->i - count)), count)))
		exit(1);
	ft_putstr(format);
	free(format);
	format = NULL;
}

static void			begin(t_printf *data)
{
	int		count;

	count = 0;
	if (ft_strcmp(data->format2, "%") == 0)
		return ;
	while (data->format2[data->i] != '\0')
	{
		if (data->format2[data->i] == '%')
		{
			print_format(data, count);
			initialize2(data);
			get_tags(data);
			count = 0;
		}
		else
		{
			count++;
			data->len++;
		}
		data->i++;
	}
	print_format(data, count);
}

int					ft_printf(const char *format, ...)
{
	t_printf	*data;

	if (!(data = malloc(sizeof(t_printf))))
		return (-1);
	va_start(data->ap, format);
	initialize(data, format);
	if (format)
		begin(data);
	va_end(data->ap);
	free(data);
	return (data->len);
}
