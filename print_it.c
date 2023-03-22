/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:01:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/22 19:04:20 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	int	i;

	printf("---map---\nwidth: %d\nheight: %d\n", \
		map->width, map->height);
	i = -1;
	while (++i < map->height * map->width)
	{
		printf("(%d, %d) ", (map->map)[i].x, (map->map)[i].y);
		if ((i + 1) % map->width)
			printf("\n");
	}
}
