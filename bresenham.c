/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 16:39:21 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_bresenham_x(int e, t_dot curr, t_dot diff, t_img *img)
{
	int	i;
	int	p;

	p = 2 * diff.y - diff.x;
	i = -1;
	while (++i < diff.x)
	{
		my_mlx_pixel_put(img, curr.x, curr.y, 0x00FF00);
		if (p < 0)
			p += 2 * diff.y;
		else
		{
			p += 2 * (diff.y - diff.x);
			curr.y++;
		}
		if (e > 0)
			curr.x++;
		else
			curr.x--;
	}
}

void	_bresenham_y(int e, t_dot curr, t_dot diff, t_img *img)
{
	int	i;
	int	p;

	p = 2 * diff.x - diff.y;
	i = -1;
	while (++i < diff.y)
	{
		my_mlx_pixel_put(img, curr.x, curr.y, 0x00FF00);
		if (p < 0)
			p += 2 * diff.x;
		else
		{
			p += 2 * (diff.x - diff.y);
			curr.x++;
		}
		if (e > 0)
			curr.y++;
		else
			curr.y--;
	}
}

void	bresenham(t_dot *d1, t_dot *d2, t_img *img)
{
	t_dot	curr;
	t_dot	diff;

	curr.x = d1->x;
	curr.y = d1->y;
	diff.x = abs(d2->x - d1->x);
	diff.y = abs(d2->y - d1->y);
	if (diff.x >= diff.y)
		_bresenham_x(d2->x - d1->x, curr, diff, img);
	else
		_bresenham_y(d2->y - d1->y, curr, diff, img);
}
