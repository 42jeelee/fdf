/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:57:20 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/26 21:45:08 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_coordinate(t_dot *dot, double angle, t_dot *base)
{
	int	x;

	x = dot->x;
	dot->x = (x - base->x)*cos(angle * M_PI / 180) - (dot->y - base->y) * sin(angle * M_PI / 180) + base->x;
	dot->y = (x - base->x)*sin(angle * M_PI / 180) + (dot->y - base->y) * cos(angle * M_PI / 180) + base->y;
}

t_dot	get_max(t_map *map)
{
	t_dot	dot;
	t_dot	max;
	int		i;

	max.x = 0;
	max.y = 0;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = (map->map)[i];
		if (dot.x > max.x)
			max.x = dot.x;
		if (dot.y > max.y)
			max.y = dot.y;
	}
	return (max);
}

t_dot	adj_coordinate(t_map *map)
{
	t_dot	*dot;
	t_dot	min;
	int		i;

	min.x = 2147483647;
	min.y = 2147483647;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &(map->map)[i];
		if (dot->x < min.x)
			min.x = dot->x;
		if (dot->y < min.y)
			min.y = dot->y;
	}
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &(map->map)[i];
		if (min.x < 0)
			dot->x += abs(min.x);
		if (min.y < 0)
			dot->y += abs(min.y);
		dot->x += WINDOW_MARGIN;
		dot->y += WINDOW_MARGIN;
	}
	return (get_max(map));
}

t_dot	set_coordinate(int gap, t_map *map)
{
	t_dot	base;
	t_dot	*dot;
	int		i;

	base.x = map->height / 2;
	base.y = map->width / 2;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &((map->map)[i]);
		dot->x = (dot->x * gap);
		dot->y = (dot->y * gap);
		rotate_coordinate(dot, 25, &base);
	}
	return (adj_coordinate(map));
}
