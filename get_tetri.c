/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 00:50:51 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 00:51:05 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//determines the limits of tetri - smallest x and y value and largest x and y value
void	get_limits(char *str, t_vec *min, t_vec *max)
{
	int i;

	i = 0;
	while (str[i])
	{
		//for each block
		if (str[i] == '#')
		{
			//change the char from # to alpha value
			//str[i] = c;
			//if index in line is less than min x value, change it
			if (i % 5 < min->x)
				min->x = i % 5;
			//if index in line is greater that max x, change it
			if (i % 5 > max->x)
				max->x = i % 5;
			//if line number is less than min y, change it
			if (i / 5 < min->y)
				min->y = i / 5;
			//if line number is greater than max y, change it
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

//gets the tetri struct
t_tet	*get_tetri(char *str, char c)
{
	t_vec	*min;
	t_vec	*max;
	t_tet	*tetri;
	char	**pos;
	int		i;

	min = new_vector(3, 3);
	max = new_vector(0, 0);
	get_limits(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], (str + min->x + (i + min->y) * 5), (max->x - min->x + 1));
		i++;
	}
	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, c);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

//checks to make sure that all the blocks are touching other blocks
int		block_continuity(char *str)
{
	int i;
	int cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 0 && str[i - 1] == '#')
				cont++;
			if (i < 20 && str[i + 1] == '#')
				cont++;
			if (i > 4 && str[i - 5] == '#')
				cont++;
			if (i < 15 && str[i + 5] == '#')
				cont++;
		}
		i++;
	}
	if (cont == 6 || cont == 8)
		return (1);
	return (0);
}


//Makes sure the inputed tet is valid
int		is_valid_input(char *str, int size_read)
{
	int i;
	int	blocks;

	i = 0;
	blocks = 0;
	if (size_read == 21 && str[20] != '\n')
		return (0);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '.' && str[i] != '#')
				return (0);
			if (str[i] == '#' && ++blocks > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return(0);
		i++;
	}
	if (!block_continuity(str))
		return (0);
	return (1);
}