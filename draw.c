/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 17:21:52 by jeelee           ###   ########.fr       */
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
		my_mlx_pixel_put(img, curr.x, curr.y, 0x00ffff00);
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
