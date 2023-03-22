/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:19 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 01:32:20 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;
	t_map	*map;

	if (ac != 2)
		return (-1);
	map = get_map(av[1]);
	if (!map)
		return (-1);
	set_gap(map, &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "fdf");
	img.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.size_line, &img.endian);
	set_coordinate(map, &mlx);
	print_xy(map);
	draw_image(map, &img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	free_map(map);
	return (0);
}
