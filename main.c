/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:57:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/06 14:51:57 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

// t_vec	*new_vector(int x, int y);
// void	print_list(t_list *list);

// int		ft_tabcmp(char **s1, char **s2, int height)
// {
// 	int i;

// 	i = 0;
// 	while (i < height)
// 	{
// 		if (ft_strequ(s1[i], s2[i]) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// t_list	*ft_lstrev(t_list **list)
// {
// 	t_list	*next;
// 	t_list	*current;
// 	t_list	*prev;

// 	prev = NULL;
// 	current = *list;
// 	while (current)
// 	{
// 		next = current->next;
// 		current->next = prev;
// 		prev = current;
// 		current = next;
// 	}
// 	*list = prev;
// 	return(*list);
// }

// void	free_tetri(t_tet *tetri)
// {
// 	int i;

// 	i = 0;
// 	while (i < tetri->height)
// 	{
// 		ft_memdel((void **)&(tetri->tab[i]));
// 		i++;
// 	}
// 	ft_memdel((void **)&(tetri->tab));
// 	ft_memdel((void **)&tetri);
// }

// int		ft_lstcount(t_list *list)
// {
// 	if(list->next == NULL)
// 		return (1);
// 	return (1 + ft_lstcount(list->next));
// }

// t_list	*free_list(t_list *list)
// {
// 	t_tet	*tetri;
// 	t_list	*next;

// 	while (list)
// 	{
// 		tetri = (t_tet *)(list->content);
// 		free_tetri(tetri);
// 		next = list->next;
// 		ft_memdel((void **)&list);
// 		list = next;
// 	}
// 	return (NULL);
// }

// void	free_map(t_map *map)
// {
// 	int i;

// 	i = 0;
// 	while (i < map->size)
// 	{
// 		ft_memdel((void **)&(map->grid[i]));
// 		i++;
// 	}
// 	ft_memdel((void **)&(map->grid));
// 	ft_memdel((void **)&map);
// }

// void	print_map(t_map *map)
// {
// 	int i;

// 	i = 0;
// 	while (i < map->size)
// 	{
// 		ft_putendl(map->grid[i]);
// 		i++;
// 	}
// }

// t_map	*new_map(int size)
// {
// 	t_map	*map;
// 	int		i;
// 	int		j;

// 	map = (t_map *)ft_memalloc(sizeof(t_map));
// 	map->size = size;
// 	map->grid = (char **)ft_memalloc(sizeof(char *) * size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		map->grid[i] = ft_strnew(size);
// 		j = 0;
// 		while (j < size)
// 		{
// 			map->grid[i][j] = '.';
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (map);
// }

// int			redundant_move(t_tet *tetri, int x, int y)
// {
// 	t_list	*link;
// 	t_tet	*temp;
// 	int		match;

// 	match = 0;
// 	link = g_list;
// 	while (link)
// 	{
// 		temp = (t_tet *)(link->content);
// 		if (temp->val < tetri->val)
// 		{
// 			if ( temp->height == tetri->height && temp->width == tetri->width
// 				&& (ft_tabcmp(tetri->tab, temp->tab, temp->height)))
// 			{
// 				match = 1;
// 				if (temp->y < y || (temp->y == y && temp->x < x))
// 					return (0);
// 			}
// 		}
// 		link = link->next;
// 	}
// 	return (match);
// }
// int		redundant_move(t_list **list, t_tet *tetri, t_vec *depth)
// {
// 	t_list	*link;
// 	t_tet	*temp;
// 	t_vec	*dist;

// 	link = *list;
// 	while (link)
// 	{
// 		temp = (t_tet *)(link->content);
// 		if (!(temp->val < tetri->val))
// 			return (0) ;
// 		if ( temp->height == tetri->height && (ft_tabcmp(tetri->tab, temp->tab, temp->height)))
// 		{
// 			dist = (t_vec *)(temp->dist);
// 			// ft_putnbr(dist->y);
// 			// ft_putchar('\n');
// 			// ft_putnbr(dist->x);
// 			// ft_putchar('\n');
// 			if (dist->y == 0 && dist->x == 0)
// 			{
// 				ft_memdel((void **)&depth);
// 				return (0);
// 			}
// 			else if (dist->y < depth->y || (dist->y == depth->y && dist->x > depth->x))
// 			{
// 				ft_memdel((void **)&depth);
// 				return (0);
// 			}
// 		}
		
// 		link = link->next;
// 	}
// 	ft_memdel((void **)&depth);
// 	return (1);
// }

// void	alter_map(t_tet *tetri, t_map *map, t_vec *pos, char c)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < tetri->height)
// 	{
// 		i = 0;
// 		while (i < tetri->width)
// 		{
// 			if (tetri->tab[j][i] == '#')
// 			{
// 				map->grid[pos->y + j][pos->x + i] = c;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	ft_memdel((void **)&pos);
// }

// void	update_glst(char c, int x, int y)
// {
// 	t_list	*link;
// 	t_tet	*tetri;

// 	link = g_list;
// 	while (link)
// 	{
// 		tetri = (t_tet *)(link->content);
// 		if (tetri->val == c)
// 		{
// 			tetri->y = y;
// 			tetri->x = x;
// 			break ;
// 		}
// 		link = link->next;
// 	}
// }

// int		evaluate_position(t_tet *tetri, t_map *map, int x, int y)
// {
// 	int	i;
// 	int	j;
	
// 	j = 0;
// 	while (j < tetri->height)
// 	{
// 		i = 0;
// 		while(i < tetri->width)
// 		{
// 			if (tetri->tab[j][i] == '#' && map->grid[y + j][x + i] != '.')
// 				return (0);
// 			i++;
// 		}
// 		j++;
// 	}
// 	if (redundant_move(tetri, x, y) == 1)
// 		return (0);
// 	tetri->y = y;
// 	tetri->x = x;
// 	update_glst(tetri->val, x, y);
// 	alter_map(tetri, map, new_vector(x, y), tetri->val);
// 	return (1);
// }

// int		solve_map(t_map *map, t_list *list)
// {
// 	int	i;
// 	int	j;
// 	t_tet	*tetri;

// 	if (list == NULL)
// 		return (1);
// 	tetri = (t_tet *)(list->content);
// 	j = 0;
// 	while (j < map->size - tetri->height + 1)
// 	{
// 		i = 0;
// 		while (i < map->size - tetri->width + 1)
// 		{
// 			if (evaluate_position(tetri, map, i, j))
// 			{
// 				if (solve_map(map, list->next))
// 					return (1);
// 				else
// 					alter_map(tetri, map, new_vector(i, j), '.');
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

// int		sqrt_ceiling(int n)
// {
// 	int		size;
// 	size = 2;
// 	while(size * size < n)
// 		size++;
// 	return (size);
// }

// t_map	*init_solver(t_list *list)
// {
// 	t_map	*map;
// 	int		size;


// 	int cnt = ft_lstcount(list);
// 	size = sqrt_ceiling(cnt * 4);//if non solid / tot = 87.5%, 69%
// 	map = new_map(size);
// 	while (!solve_map(map, list))
// 	{
// 		size++;
// 		free_map(map);
// 		map = new_map(size);
// 	}
// 	return (map);
// }

// // //this is here for debugging purposes only
// void	print_list(t_list *list)
// {
// 	t_list	*link;
// 	t_tet	*temp;
// 	int		i;

// 	link = list;
// 	while (link != NULL)
// 	{
// 		temp = (t_tet *)(link->content);
// 		i = 0;
// 		while (i < temp->height)
// 		{
// 			ft_putendl(temp->tab[i]);
// 			i++;
// 		}
// 		link = link->next;
// 	}
// }


//mallocs and creates new tetri
// t_tet	*new_tetri(char **pos, int w, int h, char c)
// {
// 	t_tet	*tetri;


// 	tetri = ft_memalloc(sizeof(t_tet));
// 	tetri->tab = pos;
// 	tetri->width = w;
// 	tetri->height = h;
// 	tetri->val = c;
// 	tetri->x = 0;
// 	tetri->y = 0;
// 	return (tetri);
// }

//mallocs and creates new vector. Vectors will be used to identify locations on grid w/o 
//having to continually pass two parameters 
// t_vec	*new_vector(int x, int y)
// {
// 	t_vec *vector;

// 	vector = ft_memalloc(sizeof(t_vec));
// 	vector->x = x;
// 	vector->y = y;
// 	return (vector);
// }


// //determines the limits of tetri - smallest x and y value and largest x and y value
// void	get_limits(char *str, t_vec *min, t_vec *max)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		//for each block
// 		if (str[i] == '#')
// 		{
// 			//change the char from # to alpha value
// 			//str[i] = c;
// 			//if index in line is less than min x value, change it
// 			if (i % 5 < min->x)
// 				min->x = i % 5;
// 			//if index in line is greater that max x, change it
// 			if (i % 5 > max->x)
// 				max->x = i % 5;
// 			//if line number is less than min y, change it
// 			if (i / 5 < min->y)
// 				min->y = i / 5;
// 			//if line number is greater than max y, change it
// 			if (i / 5 > max->y)
// 				max->y = i / 5;
// 		}
// 		i++;
// 	}
// }

// //gets the tetri struct
// t_tet	*get_tetri(char *str, char c)
// {
// 	t_vec	*min;
// 	t_vec	*max;
// 	t_tet	*tetri;
// 	char	**pos;
// 	int		i;

// 	min = new_vector(3, 3);
// 	max = new_vector(0, 0);
// 	get_limits(str, min, max);
// 	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
// 	i = 0;
// 	while (i < max->y - min->y + 1)
// 	{
// 		pos[i] = ft_strnew(max->x - min->x + 1);
// 		ft_strncpy(pos[i], (str + min->x + (i + min->y) * 5), (max->x - min->x + 1));
// 		i++;
// 	}
// 	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, c);
// 	ft_memdel((void **)&min);
// 	ft_memdel((void **)&max);
// 	return (tetri);
// }

// //checks to make sure that all the blocks are touching other blocks
// int		block_continuity(char *str)
// {
// 	int i;
// 	int cont;

// 	i = 0;
// 	cont = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '#')
// 		{
// 			if (i > 0 && str[i - 1] == '#')
// 				cont++;
// 			if (i < 20 && str[i + 1] == '#')
// 				cont++;
// 			if (i > 4 && str[i - 5] == '#')
// 				cont++;
// 			if (i < 15 && str[i + 5] == '#')
// 				cont++;
// 		}
// 		i++;
// 	}
// 	if (cont == 6 || cont == 8)
// 		return (1);
// 	return (0);
// }


// //Makes sure the inputed tet is valid
// int		is_valid_input(char *str, int size_read)
// {
// 	int i;
// 	int	blocks;

// 	i = 0;
// 	blocks = 0;
// 	if (size_read == 21 && str[20] != '\n')
// 		return (0);
// 	while (i < 20)
// 	{
// 		if (i % 5 < 4)
// 		{
// 			if (str[i] != '.' && str[i] != '#')
// 				return (0);
// 			if (str[i] == '#' && ++blocks > 4)
// 				return (0);
// 		}
// 		else if (str[i] != '\n')
// 			return(0);
// 		i++;
// 	}
// 	if (!block_continuity(str))
// 		return (0);
// 	return (1);
// }

//reads the source file and call functions to 
// t_list	*read_source(int fd)
// {
// 	char	*buf;		//Write into buf from file
// 	int		size_read;  //Number of bytes read in 
// 	t_tet	*tetri;
// 	t_list	*list;
// 	char	c;

// 	buf = ft_strnew(21);
// 	list = NULL;
// 	c = 'A';
// 	while ((size_read = read(fd, buf, 21)) >= 20)
// 	{
// 		if (!(is_valid_input(buf, size_read)) || (tetri = get_tetri(buf, c)) == NULL || ++c > 'Z')
// 			return (free_list(list));
// 		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
// 		ft_lstadd(&g_list, ft_lstnew(tetri, sizeof(t_tet)));
// 	}
// 	ft_strdel(&buf);
// 	if (size_read != 0)
// 		return(free_list(list));
// 	ft_lstrev(&list);
// 	return (list);
// }

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_map	*map;

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
	ft_putendl("going to read source");
	if (!(list = read_source(fd)))
	{
		ft_putendl("List is NULL");
		return (0);
	}
	map = init_solver(list);
	print_map(map);
	return (0);
}


