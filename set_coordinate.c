/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 00:45:05 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	adj_coordinate(t_mlx *mlx)
{
	t_dot	*dot;
	t_dot	diff;
	int		i;

	diff.x = (mlx->width / 2) - ((mlx->map)->mid)->x;
	diff.y = (mlx->height / 2) - ((mlx->map)->mid)->y;
	i = -1;
	while (++i < (mlx->map)->width * (mlx->map)->height)
	{
		dot = &((mlx->map)->map)[i];
		dot->x += diff.x;
		dot->y += diff.y;
	}
}

void	set_coordinate(t_mlx *mlx)
{
	t_dot	*dot;
	t_dot	max;
	t_dot	base;
	int		i;

	base.x = (mlx->map)->width / 2;
	base.y = (mlx->map)->height / 2;
	base.z = (mlx->map)->high / 2;
	i = -1;
	while (++i < (mlx->map)->width * (mlx->map)->height)
	{
		dot = &((mlx->map)->map)[i];
		if (dot->x == base.x - 1 && dot->y == base.y - 1)
			(mlx->map)->mid = dot;
		dot->x *= mlx->gap;
		dot->y *= mlx->gap;
		dot->z *= (mlx->cam).h;
		rotate_z(dot, (mlx->cam).z_angle, &base);
		rotate_y(dot, (mlx->cam).y_angle, &base);
		rotate_x(dot, (mlx->cam).x_angle, &base);
	}
	max = get_max(mlx->map);
	mlx->width = max.x + (WINDOW_MARGIN * 2);
	mlx->height = max.y + (WINDOW_MARGIN * 2);
	adj_coordinate(mlx);
}

void	update_coordinate(t_mlx *mlx)
{
	t_dot	*dot;
	t_dot	base;
	int		i;

	base.x = (mlx->map)->width / 2;
	base.y = (mlx->map)->height / 2;
	base.z = (mlx->map)->high / 2;
	i = -1;
	while (++i < (mlx->map)->width * (mlx->map)->height)
	{
		dot = &((mlx->map)->map)[i];
		if (dot->x == base.x - 1 && dot->y == base.y - 1)
			(mlx->map)->mid = dot;
		dot->x *= mlx->gap;
		dot->y *= mlx->gap;
		dot->z *= (mlx->cam).h;
		rotate_z(dot, (mlx->cam).z_angle, &base);
		rotate_y(dot, (mlx->cam).y_angle, &base);
		rotate_x(dot, (mlx->cam).x_angle, &base);
	}
	adj_coordinate(mlx);
}
