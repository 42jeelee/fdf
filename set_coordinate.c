/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:57:20 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/26 20:44:12 by jeelee           ###   ########.fr       */
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

void	set_coordinate(t_map *map, t_mlx *mlx)
{
	t_dot	max;
	t_dot	base;
	t_dot	*dot;
	int		i;

	base.x = map->height / 2;
	base.y = map->width / 2;
	max.x = 0;
	max.y = 0;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &((map->map)[i]);
		dot->x = (dot->x * mlx->gap);
		dot->y = (dot->y * mlx->gap);
		rotate_coordinate(dot, -35, &base);
		dot->x += WINDOW_MARGIN;
		dot->y += WINDOW_MARGIN;
		if (max.x < dot->x)
			max.x = dot->x;
		if (max.y < dot->y)
			max.y = dot->y;
	}
}
