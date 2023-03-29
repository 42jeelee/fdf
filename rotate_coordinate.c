/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 19:17:39 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_dot *dot, double angle, t_dot *base)
{
	int	y;

	y = dot->y;
	dot->y = (y - base->y) * cos(angle * M_PI / 180) - (dot->z - base->z) * \
		sin(angle * M_PI / 180) + base->y;
	dot->z = (y - base->y) * sin(angle * M_PI / 180) + (dot->z - base->z) * \
		cos(angle * M_PI / 180) + base->z;
}

void	rotate_y(t_dot *dot, double angle, t_dot *base)
{
	int	x;

	x = dot->x;
	dot->x = (x - base->x) * cos(angle * M_PI / 180) + (dot->z - base->z) * \
		sin(angle * M_PI / 180) + base->x;
	dot->z = -(x - base->x) * sin(angle * M_PI / 180) + (dot->z - base->z) * \
		cos(angle * M_PI / 180) + base->y;
}

void	rotate_z(t_dot *dot, double angle, t_dot *base)
{
	int	x;

	x = dot->x;
	dot->x = (x - base->x) * cos(angle * M_PI / 180) - (dot->y - base->y) * \
		sin(angle * M_PI / 180) + base->x;
	dot->y = (x - base->x) * sin(angle * M_PI / 180) + (dot->y - base->y) * \
		cos(angle * M_PI / 180) + base->y;
}
