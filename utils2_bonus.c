/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:55:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/04 21:40:28 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_in_string(char c, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i] \
			|| (('A' <= str[i] && str[i] <= 'Z') && c == str[i] + 32) \
			|| (('a' <= str[i] && str[i] <= 'z') && c == str[i] - 32))
			return (i);
	}
	return (-1);
}

int	map_widthjoin(t_map *map)
{
	t_dot	*new;
	int		i;

	if (map->width == 0)
		return (error_massage(ANSI_RED "NO DATA\n" ANSI_RES, -1));
	new = (t_dot *)malloc(sizeof(t_dot) * (map->width * map->height));
	if (!new)
		return (-1);
	i = -1;
	while (++i < map->width * (map->height - 1))
		new[i] = (map->mapinit)[i];
	if (map->mapinit)
		free(map->mapinit);
	map->mapinit = new;
	return (0);
}

t_dot	get_min(t_map *map)
{
	t_dot	min;
	t_dot	dot;
	int		i;

	min.x = 2147483647;
	min.y = 2147483647;
	min.z = 0;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = (map->map)[i];
		if (dot.x < min.x)
			min.x = dot.x;
		if (dot.y < min.y)
			min.y = dot.y;
	}
	return (min);
}

t_dot	get_max(t_map *map)
{
	t_dot	dot;
	t_dot	min;
	t_dot	max;
	int		i;

	max.x = 0;
	max.y = 0;
	max.z = 0;
	min = get_min(map);
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = (map->map)[i];
		if (min.x < 0)
			dot.x += abs(min.x);
		if (min.y < 0)
			dot.y += abs(min.y);
		if (dot.x > max.x)
			max.x = dot.x;
		if (dot.y > max.y)
			max.y = dot.y;
	}
	return (max);
}

void	setting_dot_color(t_dot *dot, int color, t_map *map)
{
	const int	color_value[6] = {0x0000FF, 0x00FF00, 0xFF0000};
	int			i;

	dot->color = 0xFFFFFF;
	i = -1;
	while (++i < map->high - map->low)
	{
		if (dot->z == map->low + i + 1)
		{
			dot->color = get_color(0xFFFFFF, color_value[color - 1], \
				i, map->high - map->low);
			break ;
		}
	}
}
