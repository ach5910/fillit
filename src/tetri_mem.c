/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 00:54:48 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 00:55:02 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*new_tetri(char **pos, int w, int h, char c)
{
	t_tet	*tetri;

	tetri = ft_memalloc(sizeof(t_tet));
	tetri->tab = pos;
	tetri->width = w;
	tetri->height = h;
	tetri->val = c;
	tetri->x = 0;
	tetri->y = 0;
	return (tetri);
}

void	free_tetri(t_tet *tetri)
{
	int i;

	i = 0;
	while (i < tetri->height)
	{
		ft_memdel((void **)&(tetri->tab[i]));
		i++;
	}
	ft_memdel((void **)&(tetri->tab));
	ft_memdel((void **)&tetri);
}
