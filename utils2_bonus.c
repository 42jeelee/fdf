/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:55:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 00:56:02 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
