/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/20 20:01:28 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenhams(t_dot d1, t_dot d2, t_vars *vars)
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
		mlx_pixel_put(vars->mlx, vars->win, curr.x, curr.y, 0xFFFFFF);
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
