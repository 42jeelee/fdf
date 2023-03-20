/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/20 19:58:08 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include <stdlib.h>

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

void	bresenhams(t_dot d1, t_dot d2, t_vars *vars);

int		key_hook(int keycode, t_vars *vars);

#endif