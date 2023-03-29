/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:45:06 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 15:28:56 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dot_color(char *line, t_dot *dot, int *idx)
{
	const char	*hex = "0123456789abcdef";
	int			i;

	(*idx)++;
	if (line[(*idx)++] != '0')
		return (-1);
	if (line[(*idx)++] != 'x')
		return (-1);
	dot->color = 0;
	while (1)
	{
		i = is_in_string(line[*idx], hex);
		if (i == -1)
			break ;
		dot->color = (dot->color * 16) + i;
		(*idx)++;
	}
	return (0);
}

int	map_atoi(char *line, t_dot *dot, int *idx)
{
	int	m;

	dot->z = 0;
	dot->color = 0xFFFFFF;
	m = 1;
	if (line[*idx] == '-')
	{
		m *= -1;
		(*idx)++;
	}
	while ('0' <= line[*idx] && line[*idx] <= '9')
	{
		dot->z = (dot->z * 10) + (line[*idx] - '0');
		(*idx)++;
	}
	dot->z *= m;
	if (line[*idx] == ',')
		return (get_dot_color(line, dot, idx));
	return (0);
}
