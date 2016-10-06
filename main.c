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

//this is here for debugging purposes only
void	print_list(t_list **list)
{
	ft_putendl("In print list");
	t_list	*link;
	t_tet	*temp;
	int		i;

	link = *list;
	while (link != NULL)
	{
		temp = link->content;
		i = 0;
		while (i < temp->height)
		{
			ft_putendl(temp->tab[i]);
			i++;
		}
		link = link->next;
	}
}


//mallocs and creates new tetri
t_tet	*new_tetri(char **pos, int w, int h, char c)
{
	t_tet	*tetri;

	tetri = ft_memalloc(sizeof(t_tet));
	tetri->tab = pos;
	tetri->width = w;
	tetri->height = h;
	tetri->val = c;
	return (tetri);
}

//mallocs and creates new vector. Vectors will be used to identify locations on grid w/o 
//having to continually pass two parameters 
t_vec	*new_vector(int x, int y)
{
	t_vec *vector;

	vector = ft_memalloc(sizeof(t_vec));
	vector->x = x;
	vector->y = y;
	return (vector);
}


//determines the limits of tetri - smallest x and y value and largest x and y value
void	get_limits(char *str, t_vec *min, t_vec *max, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		//for each block
		if (str[i] == '#')
		{
			//change the char from # to alpha value
			str[i] = c;
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

	//create min vector - init to largest extreme
	min = new_vector(3, 3);
	//create max vector - init to smallest extreme
	max = new_vector(0, 0);

	get_limits(str, min, max, c);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));//amount of strings = tetri height
	i = 0;
	while (i < max->y - min->y + 1)
	{
		//size is = to tetri width 
		pos[i] = ft_strnew(max->x - min->x + 1);
		//get each line   ptr + min x value + ( index + min height ) * 5(number of chars per line) 
		ft_strncpy(pos[i], (str + min->x + (i + min->y) * 5), (max->x - min->x + 1));
		i++;
	}
	// i = 0;
	// while (i < max->y - min->y + 1)
	// {
	// 	ft_putendl(pos[i]);
	// 	i++;
	// }
	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, c);
	//free min and max
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
			//check left of block
			if (i > 0 && str[i - 1] == '#')
				cont++;
			//check right of block
			if (i < 20 && str[i + 1] == '#')
				cont++;
			//check above block(visually)...empirically below
			if (i > 4 && str[i - 5] == '#')
				cont++;
			//check below block ''  ''  ''
			if (i < 15 && str[i + 5] == '#')
				cont++;
		}
		i++;
	}
	//All tetri have a conection count of 6, except for the square which has 8
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
	//if not last tetri then it needs to be followed by a new line
	if (size_read == 21 && str[20] != '\n')
		return (0);
	while (i < 20)
	{
		//if index is part of the grid. ex i= 0 thru 3 are part of tetri grid
		if (i % 5 < 4)
		{
			//invalid char in grid
			if (str[i] != '.' && str[i] != '#')
				return (0);
			//too many blocks in tetri
			if (str[i] == '#' && ++blocks > 4)
				return (0);
		}
		else if (str[i] != '\n')//when index mod 5 == 4 it should be  newline char
			return(0);
		i++;
	}
	if (!block_continuity(str))
		return (0);
	return (1);
}

//reads the source file and call functions to 
t_list	*read_source(int fd)
{
	char	*buf;		//Write into buf from file
	int		size_read;  //Number of bytes read in 
	t_tet	*tetri;
	t_list	*list;
	char	c;
//	int errnum;

	buf = ft_strnew(21);//21 because 4 * 4 grid w/ newline at each line and newline after
	list = NULL;
	c = 'A';
	while ((size_read = read(fd, buf, 21)) >= 20)//The last tetrimino will be 20 bytes cuz no newline after
	{
		if (!(is_valid_input(buf, size_read)) || (tetri = get_tetri(buf, c)) == NULL)
		{
			//ft_memdel((void **)&buf);
			//free list
			ft_putnbr(errnum);
			ft_putendl("\nFailed if");
			return (NULL);
		}
		c++;
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
		//free tetris ??
	}
	//ft_memdel((void **)&buf);
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

	//Only accept one arguement
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetrimino_source_file");
		return (0);
	}//open the file passed in 
	if ((fd = open(argv[1], O_RDONLY, 0600)) == -1)
	{
		ft_putendl("File wouldn't open");
		return (0);
	}
	ft_putendl("going to read source");
	list = read_source(fd);
	print_list(&list);
}