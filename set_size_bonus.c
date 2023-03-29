/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:03:08 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 03:07:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_size(t_mlx *mlx)
{
	mlx->gap = 42;
	set_coordinate(mlx);
	while (mlx->width > WINDOW_MAX_WIDTH || \
		mlx->height > WINDOW_MAX_HEIGHT)
	{
		if (mlx->gap == 10)
			(mlx->cam).h = 5;
		else if (mlx->gap == 5)
			(mlx->cam).h = 2;
		else if (mlx->gap == 1)
			break ;
		(mlx->gap)--;
		map_init(mlx->map);
		set_coordinate(mlx);
	}
}
