/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:03:08 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 23:47:07 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_size(t_mlx *mlx)
{
	mlx->gap = 42;
	set_coordinate(mlx);
	while (mlx->width > WINDOW_MAX_WIDTH || \
		mlx->height > WINDOW_MAX_HEIGHT)
	{
		(mlx->gap)--;
		map_init(mlx->map);
		set_coordinate(mlx);
	}
}
