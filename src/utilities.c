/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 01:21:31 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 04:31:59 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fillit.h"

t_vec	*new_vector(int x, int y)
{
	t_vec *vector;

	vector = ft_memalloc(sizeof(t_vec));
	vector->x = x;
	vector->y = y;
	return (vector);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
}

int		sqrt_ceiling(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void	update_glst(char c, int x, int y)
{
	t_list	*link;
	t_tet	*tetri;

	link = g_list;
	while (link)
	{
		tetri = (t_tet *)(link->content);
		if (tetri->val == c)
		{
			tetri->y = y;
			tetri->x = x;
			break ;
		}
		link = link->next;
	}
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->grid[i]);
		i++;
	}
}
