/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 04:08:45 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	all_setting_coordinate(t_dot *dot, t_cam *cam, t_dot *base)
{
	rotate_z(dot, cam->z_angle, base);
	rotate_y(dot, cam->y_angle, base);
	rotate_x(dot, cam->x_angle, base);
	scale_dot(dot, cam->big);
}

void	trans_dot(t_map *map, t_cam *cam)
{
	t_dot	*dot;
	int		i;

	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &(map->map)[i];
		dot->x += cam->x;
		dot->y += cam->y;
	}
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

	base.x = (mlx->map)->width / 2 + 1;
	base.y = (mlx->map)->height / 2 + 1;
	base.z = (mlx->map)->high / 2 + 1;
	i = -1;
	while (++i < (mlx->map)->width * (mlx->map)->height)
	{
		dot = &((mlx->map)->map)[i];
		if (dot->x == base.x - 1 && dot->y == base.y - 1)
			(mlx->map)->mid = dot;
		dot->x *= mlx->gap;
		dot->y *= mlx->gap;
		dot->z *= (mlx->cam).h;
		all_setting_coordinate(dot, &(mlx->cam), &base);
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

	base.x = (mlx->map)->width / 2 + 1;
	base.y = (mlx->map)->height / 2 + 1;
	base.z = (mlx->map)->high / 2 + 1;
	i = -1;
	while (++i < (mlx->map)->width * (mlx->map)->height)
	{
		dot = &((mlx->map)->map)[i];
		if (dot->x == base.x - 1 && dot->y == base.y - 1)
			(mlx->map)->mid = dot;
		dot->x *= mlx->gap;
		dot->y *= mlx->gap;
		dot->z *= (mlx->cam).h;
		all_setting_coordinate(dot, &(mlx->cam), &base);
	}
	adj_coordinate(mlx);
	trans_dot(mlx->map, &(mlx->cam));
}
