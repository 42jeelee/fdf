/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:03:08 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 17:57:35 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_base(t_dot max, t_mlx *mlx)
{
	if (!max.x)
	{
		(mlx->base).x = (mlx->map)->width / 2;
		(mlx->base).y = (mlx->map)->height / 2;
		(mlx->base).z = (mlx->map)->high / 2;
	}
	else
	{
		(mlx->base).x = max.x + WINDOW_MARGIN;
		(mlx->base).y = max.y + WINDOW_MARGIN;
		(mlx->base).z = max.z + WINDOW_MARGIN;
	}
}

void	set_size(t_mlx *mlx)
{
	t_dot	max;

	mlx->gap = 42;
	max.x = 0;
	get_base(max, mlx);
	max = set_coordinate(mlx->gap, mlx->map);
	get_base(max, mlx);
	while (max.x + WINDOW_MARGIN > WINDOW_MAX_WIDTH || \
		max.y + WINDOW_MARGIN > WINDOW_MAX_HEIGHT)
	{
		(mlx->gap)--;
		map_init(mlx->map);
		max = set_coordinate(mlx->gap, mlx->map);
		get_base(max, mlx);
	}
	mlx->width = max.x + WINDOW_MARGIN;
	mlx->height = max.y + WINDOW_MARGIN;
}
