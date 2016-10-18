/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 01:19:06 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/18 02:42:02 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		evaluate_position(t_tet *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while (i < tetri->width)
		{
			if (tetri->tab[j][i] == '#' && map->grid[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	if (redundant_move(tetri, x, y) == 1)
		return (0);
	tetri->y = y;
	tetri->x = x;
	update_glst(tetri->val, x, y);
	alter_map(tetri, map, new_vector(x, y), tetri->val);
	return (1);
}

void	alter_map(t_tet *tetri, t_map *map, t_vec *pos, char c)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while (i < tetri->width)
		{
			if (tetri->tab[j][i] == '#')
			{
				map->grid[pos->y + j][pos->x + i] = c;
			}
			i++;
		}
		j++;
	}
	ft_memdel((void **)&pos);
}

int		redundant_move(t_tet *tetri, int x, int y)
{
	t_list	*link;
	t_tet	*temp;
	int		match;

	match = 0;
	link = g_list;
	while (link)
	{
		temp = (t_tet *)(link->content);
		if (temp->val < tetri->val)
		{
			if (temp->height == tetri->height && temp->width == tetri->width
				&& (ft_tabcmp(tetri->tab, temp->tab, temp->height)))
			{
				match = 1;
				if (temp->y < y || (temp->y == y && temp->x < x))
					return (0);
			}
		}
		link = link->next;
	}
	return (match);
}

int		ft_tabcmp(char **s1, char **s2, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (ft_strequ(s1[i], s2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
