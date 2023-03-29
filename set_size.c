/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:03:08 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 20:09:47 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_size(t_mlx *mlx)
{
	t_dot	max;

	mlx->gap = 42;
	max.x = 0;
	max = set_coordinate(mlx->gap, mlx->map, &(mlx->base));
	while (max.x + WINDOW_MARGIN > WINDOW_MAX_WIDTH || \
		max.y + WINDOW_MARGIN > WINDOW_MAX_HEIGHT)
	{
		(mlx->gap)--;
		map_init(mlx->map);
		max = set_coordinate(mlx->gap, mlx->map, &(mlx->base));
	}
	mlx->width = max.x + WINDOW_MARGIN;
	mlx->height = max.y + WINDOW_MARGIN;
}
