/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:05 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 16:25:14 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_image(t_map *map, t_img *img, t_mlx *mlx)
{
	img->width = mlx->width - (2 * WINDOW_MARGIN) + 1;
	img->height = mlx->height - (2 * WINDOW_MARGIN) + 1;
	img->img = mlx_new_image(mlx->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->size_line, &img->endian);
	draw_image(map, img);
}
