/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:43:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/20 20:00:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_vars	vars;
	t_dot	d1;
	t_dot	d2;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Title");
	d1.x = 20;
	d1.y = 20;
	d2.x = 430;
	d2.y = 380;
	bresenhams(d1, d2, &vars);
	mlx_key_hook (vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
