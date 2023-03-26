/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_gap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/26 21:44:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_gap(t_map *map, t_mlx *mlx)
{
	t_dot	max;

	mlx->gap = 42;
	max = set_coordinate(mlx->gap, map);
	while (max.x + WINDOW_MARGIN > WINDOW_MAX_WIDTH || max.y + WINDOW_MARGIN > WINDOW_MAX_HEIGHT)
	{
		(mlx->gap)--;
		max = set_coordinate(mlx->gap, map);
	}
	mlx->width = max.x + WINDOW_MARGIN;
	mlx->height = max.y + WINDOW_MARGIN;
}
