/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:39:28 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 19:10:19 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, t_dot dot, int color)
{
	char	*dst;

	if ((0 <= dot.x && dot.x < mlx->width) && \
		(0 <= dot.y && dot.y < mlx->height))
	{
		dst = (mlx->img).addr + (dot.y * (mlx->img).size_line \
			+ dot.x * ((mlx->img).bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_image(t_mlx *mlx)
{
	t_dot	*d1;
	t_dot	*d2;
	t_dot	*d3;
	int		i;

	d1 = &(((mlx->map)->map)[0]);
	i = 0;
	while (++i < mlx->map->height * mlx->map->width)
	{
		d2 = &(((mlx->map)->map)[i]);
		if (i % (mlx->map)->width)
			bresenham(d1, d2, mlx);
		if (i + (mlx->map)->width - 1 < (mlx->map)->height * (mlx->map)->width)
		{
			d3 = &(((mlx->map)->map)[i + (mlx->map)->width - 1]);
			bresenham(d1, d3, mlx);
		}
		d1 = d2;
	}
}
