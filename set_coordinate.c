/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:57:20 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 16:00:21 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coordinate(t_map *map, t_mlx *mlx)
{
	t_dot	*dot;
	int		i;

	i = -1;
	while (++i < map->width * map->height)
	{
		dot = &((map->map)[i]);
		dot->x = (dot->x * mlx->gap);
		dot->y = (dot->y * mlx->gap);
	}
}
