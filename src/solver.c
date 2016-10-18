/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 01:15:19 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 01:15:33 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*init_solver(t_list *list)
{
	t_map	*map;
	int		size;
	int		cnt;

	cnt = ft_lstcount(list);
	size = sqrt_ceiling(cnt * 4);
	map = new_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}

int		solve_map(t_map *map, t_list *list)
{
	int		i;
	int		j;
	t_tet	*tetri;

	if (list == NULL)
		return (1);
	tetri = (t_tet *)(list->content);
	j = 0;
	while (j < map->size - tetri->height + 1)
	{
		i = 0;
		while (i < map->size - tetri->width + 1)
		{
			if (evaluate_position(tetri, map, i, j))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					alter_map(tetri, map, new_vector(i, j), '.');
			}
			i++;
		}
		j++;
	}
	return (0);
}
