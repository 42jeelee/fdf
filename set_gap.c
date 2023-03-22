/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_gap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 00:00:32 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_gap(t_map *map, t_mlx *mlx)
{
	mlx->gap = 42;
	while ((map->height * mlx->gap) + WINDOW_MARGIN > WINDOW_MAX_HEIGHT || \
		(map->width * mlx->gap) + WINDOW_MARGIN > WINDOW_MAX_WIDTH)
			(mlx->gap)--;
	mlx->height = ((map->height - 1) * mlx->gap) + (WINDOW_MARGIN * 2);
	mlx->width = ((map->width - 1) * mlx->gap) + (WINDOW_MARGIN * 2);
}
