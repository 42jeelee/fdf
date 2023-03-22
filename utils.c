/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:45:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/22 19:10:47 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
			free(map->map);
		free(map);
	}
	return (0);
}

int	is_in_string(char c, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i] \
			|| (('A' <= str[i] && str[i] <= 'Z') && c == str[i] + 32) \
			|| (('a' <= str[i] && str[i] <= 'z') && c == str[i] - 32))
			return (i);
	}
	return (-1);
}

int	map_widthjoin(t_map *map)
{
	t_dot	*new;
	int		i;

	new = (t_dot *)malloc(sizeof(t_dot) * (map->width * map->height));
	if (!new)
		return (-1);
	i = -1;
	while (++i < map->width * (map->height - 1))
		new[i] = (map->map)[i];
	if (map->map)
		free(map->map);
	map->map = new;
	return (0);
}
