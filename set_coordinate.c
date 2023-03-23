/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:57:20 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 18:09:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coordinate(t_map *map, t_mlx *mlx)
{
	t_dot	max;
	t_dot	*dot;
	int		i;

	max.x = 0;
	max.y = 0;
	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &((map->map)[i]);
		dot->x = (dot->x * mlx->gap) + WINDOW_MARGIN;
		dot->y = (dot->y * mlx->gap) + WINDOW_MARGIN;
		if (max.x < dot->x)
			max.x = dot->x;
		if (max.y < dot->y)
			max.y = dot->y;
	}
}
