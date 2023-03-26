/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:20:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/26 23:23:34 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_dot *dot, double alpha)
{
	int	y;

	y = dot->y;
	dot->y = y * cos(alpha) + (dot->z) * sin(alpha);
	dot->z = -y * sin(alpha) + (dot->z) * cos(alpha);
}

void	rotate_y(t_dot *dot, double beta)
{
	int	x;

	x = dot->x;
	dot->x = x * cos(beta) + (dot->z) * sin(beta);
	dot->z = -x * sin(beta) + (dot->z) * cos(beta);
}

void	rotate_z(t_dot *dot, double gamma)
{
	int	x;

	x = dot->x;
	dot->x = x * cos(gamma) - dot->y * sin(gamma);
	dot->y = x * sin(gamma) + dot->y * cos(gamma);
}
