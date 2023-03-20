/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:43:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/20 19:12:08 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	bresenhams(int x1, int y1, int x2, int y2, t_vars *vars)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = (2 * dy) - dx;
	while (x <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
		x++;
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			y++;
		}
	}
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Title");
	mlx_key_hook (vars.win, key_hook, &vars);
	bresenhams(100, 100, 400, 400, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
