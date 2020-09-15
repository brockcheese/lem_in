/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roman.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 01:56:19 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:44 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		*get_roman_decimals(void)
{
	int		*result;
	int		i;

	i = 0;
	result = malloc(sizeof(int) * 13);
	result[i++] = 1000;
	result[i++] = 900;
	result[i++] = 500;
	result[i++] = 400;
	result[i++] = 100;
	result[i++] = 90;
	result[i++] = 50;
	result[i++] = 40;
	result[i++] = 10;
	result[i++] = 9;
	result[i++] = 5;
	result[i++] = 4;
	result[i++] = 1;
	return (result);
}

char	**get_roman_symbols(void)
{
	char	**result;
	char	*symbols;

	symbols = "M CM D CD C XC L XL X IX V IV I";
	result = ft_strsplit(symbols, ' ');
	return (result);
}
