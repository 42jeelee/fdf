/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:19 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 18:50:31 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (-1);
	mlx.map = get_map(av[1]);
	set_size(&mlx);
	print_xy(mlx.map);
	print_info(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "fdf");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	(mlx.img).addr = 0;
	set_image(&mlx);
	mlx_loop(mlx.mlx);
	free_map(mlx.map);
	return (0);
}
