/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 01:00:21 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 01:00:32 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fillit.h"

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->grid[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->grid[i]));
		i++;
	}
	ft_memdel((void **)&(map->grid));
	ft_memdel((void **)&map);
}