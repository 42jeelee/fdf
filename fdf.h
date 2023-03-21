/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 15:31:07 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_dot
{
	int	x;
	int	y;
}	t_dot;

typedef struct s_map
{
	int	z;
	int	color;
}	t_map;

typedef struct s_mapinfo
{
	int				height;
	int				width;
	struct s_map	*map;
}	t_mapinfo;

void	bresenhams(t_dot d1, t_dot d2, t_vars *vars);

int		key_hook(int keycode, t_vars *vars);

int		is_hexnumber(char c);
int		map_color(char *str, t_map *dot, int *idx);
int		map_atoi(char *str, t_map *dot, int *idx);
int		get_map(char *filename, t_mapinfo *mapinfo);

void	print_map(t_mapinfo *mapinfo);
void	print_only_z(t_mapinfo *mapinfo);

#endif