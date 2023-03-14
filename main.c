/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:43:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/14 17:28:17 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;

	width = 400;
	height = 400;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Title");
	mlx_loop(mlx_ptr);
	return (0);
}
