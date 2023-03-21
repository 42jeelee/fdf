/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_gap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:27:16 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 19:44:44 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_gap(t_vars *vars, t_mapinfo *mapinfo)
{
	vars->gap = 42;
	while ((mapinfo->height * vars->gap) + WINDOW_MARGIN > WINDOW_MAX_HEIGHT || \
		(mapinfo->width * vars->gap) + WINDOW_MARGIN > WINDOW_MAX_WIDTH)
		(vars->gap)--;
	vars->height = (mapinfo->height * vars->gap) + WINDOW_MARGIN;
	vars->width = (mapinfo->width * vars->gap) + WINDOW_MARGIN;
}
