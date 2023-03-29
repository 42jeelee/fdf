/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 15:36:10 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_dot;

typedef struct s_map
{
	int				height;
	int				width;
	struct s_dot	*map;
	struct s_dot	*mapinit;
}	t_map;

t_map	*get_map(char *filename);

int		get_dot_color(char *line, t_dot *dot, int *idx);
int		map_atoi(char *line, t_dot *dot, int *idx);

int		free_map(t_map *map);
void	map_init(t_map *map);
int		is_in_string(char c, const char *str);
int		map_widthjoin(t_map *map);

void	print_map(t_map *map);
void	print_xy(t_map *map);
void	print_color(t_map *map);

#endif
