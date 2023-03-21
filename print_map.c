/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:27:39 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 15:30:50 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_mapinfo *mapinfo)
{
	int	i;

	printf("height: %d\nwidth: %d\nmap: \n", mapinfo->height, mapinfo->width);
	i = -1;
	while (++i < mapinfo->height * mapinfo->width)
	{
		printf("[%d, %d] ", ((mapinfo->map)[i]).z, \
			((mapinfo->map)[i]).color);
		if (i && !((i + 1) % mapinfo->width))
			printf("\n");
	}
}

void	print_only_z(t_mapinfo *mapinfo)
{
	int	i;

	printf("height: %d\nwidth: %d\nmap: \n", mapinfo->height, mapinfo->width);
	i = -1;
	while (++i < mapinfo->height * mapinfo->width)
	{
		printf("%d ", ((mapinfo->map)[i]).z);
		if (i && !((i + 1) % mapinfo->width))
			printf("\n");
	}
}
