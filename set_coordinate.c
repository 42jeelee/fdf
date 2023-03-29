/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 20:29:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	get_max(t_map *map)
{
	t_dot	dot;
	t_dot	max;
	int		i;

	max.x = 0;
	max.y = 0;
	max.z = 0;
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

void	_adj_coordinate(t_map *map, t_dot *min)
{
	t_dot	*dot;
	int		i;

	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &(map->map)[i];
		if (min->x < 0)
			dot->x += abs(min->x);
		if (min->y < 0)
			dot->y += abs(min->y);
		dot->x += WINDOW_MARGIN;
		dot->y += WINDOW_MARGIN;
	}
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
	_adj_coordinate(map, &min);
	return (get_max(map));
}

t_dot	set_coordinate(int gap, t_map *map, t_dot *base)
{
	t_dot	*dot;
	int		i;

	base->x = map->width / 2;
	base->y = map->height / 2;
	base->z = map->high / 2;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &(map->map)[i];
		dot->x *= gap;
		dot->y *= gap;
		dot->z *= (gap / 3);
		rotate_z(dot, 45, base);
		rotate_y(dot, 0, base);
		rotate_x(dot, 35.264, base);
	}
	return (adj_coordinate(map));
}
