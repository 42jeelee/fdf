/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:26:10 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 19:01:15 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_hexnumber(char c)
{
	const char	*hex = "0123456789ABCDEF";
	int			i;

	i = -1;
	while (++i < 16)
	{
		if (c == hex[i] || (i > 9 && c == hex[i] + 32))
			return (i);
	}
	return (-1);
}

int	map_color(char *str, t_dot *dot, int *idx)
{
	int	tmp;

	if (str[(*idx)++] != '0')
		return (-1);
	if (str[(*idx)++] != 'x')
		return (-1);
	while (1)
	{
		tmp = is_hexnumber(str[*idx]);
		if (tmp == -1)
			break ;
		dot->color *= 16;
		dot->color += tmp;
		(*idx)++;
	}
	return (0);
}

int	color_atoi(char *str, t_dot *dot, int *idx)
{
	dot->color = 0;
	if (str[*idx] == ',')
	{
		(*idx)++;
		if (map_color(str, dot, idx) == -1)
			return (-1);
	}
	return (0);
}

int	map_atoi(char *str, t_dot *dot, int *idx)
{
	int	m;

	m = 1;
	dot->z = 0;
	if (str[*idx] == '-')
	{
		m *= -1;
		(*idx)++;
	}
	while ('0' <= str[*idx] && str[*idx] <= '9')
	{
		dot->z *= 10;
		dot->z += str[*idx] - '0';
		(*idx)++;
	}
	dot->z *= m;
	if (color_atoi(str, dot, idx) == -1)
		return (-1);
	if (str[*idx] == '\n' || str[*idx] == 0)
		return (1);
	if (str[*idx] != ' ')
		return (-1);
	while (str[*idx] == ' ')
		(*idx)++;
	return (0);
}
