/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:57:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/05 15:57:25 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
			if (str[i] != '.' || str[i] != '#')
				return (0);
			if (str[i] == "#" && ++blocks > 4)
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

t_list	*read_source(int fd)
{
	char	buf[21];
	int		size_read;
	t_tet	*tetri;
	t_list	*list;
	char	c;

	while ((size_read = read(fd, buf, 21)) >= 20)
	{
		if (!is_valid_input(buf, size_read) || (tetri = get_tetri(buf, c) == NULL))
		{
			ft_memdel((void **)&buf);
			//free list
			return (NULL);
		}
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
		//free tetris ??
	}
	ft_memdel((void **)&buf);
	if (size_read != 0)
	{
		//free list
		return (NULL);
	}
	return (list);

}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetrimino_source_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY, 0600)) == -1)
	{
		ft_putendl("File wouldn't open");
		return (0);
	}
	list = read_source(fd);
}