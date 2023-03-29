/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:44:06 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 22:51:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	destroy_image(t_mlx *mlx)
{
	if ((mlx->img).addr)
	{
		mlx_destroy_image(mlx->mlx, (mlx->img).img);
		map_init(mlx->map);
		update_coordinate(mlx);
		(mlx->img).addr = 0;
	}
}

void	set_image(t_mlx *mlx)
{
	destroy_image(mlx);
	(mlx->img).img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	(mlx->img).addr = mlx_get_data_addr((mlx->img).img, \
		&((mlx->img).bits_per_pixel), \
			&((mlx->img).size_line), &((mlx->img).endian));
	draw_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, (mlx->img).img, 0, 0);
}
