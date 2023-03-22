/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:01:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/22 19:43:17 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	int	i;

	if (!map)
		printf("MAP NULL point\n");
	else
	{
		printf("---map---\nwidth: %d\nheight: %d\n", \
			map->width, map->height);
		if (map->map)
		{
			i = -1;
			while (++i < map->height * map->width)
			{
				printf("(%d, %d) ", (map->map)[i].x, (map->map)[i].y);
				if (!((i + 1) % map->width))
					printf("\n");
			}
		}
		else
			printf("MAP->map is null\n");
	}
}
