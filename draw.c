/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 20:39:36 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenhams(t_dot d1, t_dot d2, t_img *img)
{
	t_dot	curr;
	t_dot	diff;
	int		p;

	curr.x = d1.x;
	curr.y = d1.y;
	diff.x = d2.x - d1.x;
	diff.y = d2.y - d1.y;
	p = (2 * diff.y) - diff.x;
	while (curr.x <= d2.x)
	{
		my_mlx_pixel_put(img, curr.x, curr.y, 0x00FF00);
		curr.x++;
		if (p < 0)
			p = p + (2 * diff.y);
		else
		{
			p = p + (2 * diff.y) - (2 * diff.x);
			curr.y++;
		}
	}
}

void	draw_map(t_mapinfo *mapinfo, t_vars *vars, t_img *img)
{
	t_dot	d1;
	t_dot	d2;
	t_dot	d3;
	int		i;

	print_window_size(vars);
	d1 = (mapinfo->map)[0];
	d1.x += WINDOW_MARGIN;
	d1.y += WINDOW_MARGIN;
	i = 0;
	while (++i < (mapinfo->width * mapinfo->height))
	{
		d2 = (mapinfo->map)[i];
		d2.x += WINDOW_MARGIN + (vars->gap * d2.x);
		d2.y += WINDOW_MARGIN + (vars->gap * d2.y);
		bresenhams(d1, d2, img);
		if (i + mapinfo->width - 1 < (mapinfo->width * mapinfo->height))
		{
			d3 = (mapinfo->map)[i + mapinfo->width - 1];
			d3.x += WINDOW_MARGIN + (vars->gap * d3.x);
			d3.y += WINDOW_MARGIN + (vars->gap * d3.y);
			bresenhams(d1, d3, img);
		}
		d1 = d2;
	}
}
