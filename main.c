/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:19 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/04 18:39:01 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (error_massage(ANSI_YEL "Usage :" ANSI_GRE " ./fdf" \
			ANSI_BLU " [filename]\n" ANSI_RES, -1));
	mlx.map = get_map(av[1]);
	if (!mlx.map)
		return (-1);
	cam_init(&mlx.cam);
	set_size(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "fdf");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, exit_hook, &mlx);
	(mlx.img).addr = 0;
	set_image(&mlx);
	mlx_loop(mlx.mlx);
	free_map(mlx.map);
	return (0);
}
