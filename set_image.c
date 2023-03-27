/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:05 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/27 09:55:26 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_image(t_map *map, t_img *img, t_mlx *mlx)
{
	if (img->addr)
	{
		mlx_destroy_image(mlx->mlx, img->img);
		map_init(map);
		set_coordinate(mlx->gap, map, mlx);
		img->addr = 0;
	}
}

void	set_image(t_map *map, t_img *img, t_mlx *mlx)
{
	destroy_image(map, img, mlx);
	img->width = mlx->width;
	img->height = mlx->height;
	img->img = mlx_new_image(mlx->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->size_line, &img->endian);
	draw_image(map, img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}
