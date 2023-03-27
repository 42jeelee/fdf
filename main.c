/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:19 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/27 10:48:14 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_hooks(t_param *param)
{
	mlx_mouse_hook((param->mlx).win, &mouse_hook, param);
	mlx_key_hook((param->mlx).win, &key_hook, param);
}

int	main(int ac, char **av)
{
	t_param	param;

	if (ac != 2)
		return (-1);
	param.map = get_map(av[1]);
	if (!param.map)
		return (-1);
	cam_init(&(param.mlx));
	set_gap(param.map, &(param.mlx));
	param.mlx.mlx = mlx_init();
	param.mlx.win = mlx_new_window(param.mlx.mlx, param.mlx.width, param.mlx.height, "fdf");
	param.img.addr = 0;
	add_hooks(&param);
	set_image(param.map, &(param.img), &(param.mlx));
	mlx_loop(param.mlx.mlx);
	free_map(param.map);
	return (0);
}
