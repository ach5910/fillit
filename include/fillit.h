/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:10:24 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 04:32:59 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct			s_map
{
	char		**grid;
	int			size;
}    					t_map;

typedef struct			s_vec
{
	int			x;
	int			y;
}						t_vec;

typedef struct			s_tet
{
	char		**tab;
	int			width;
	int			height;
	char		val;
	int			x;
	int			y;
}						t_tet;

t_list	*g_list;

int		main(int argc, char **argv);
void	ft_error(void);
t_list	*ft_lstrev(t_list **list);
int		ft_tabcmp(char **s1, char **s2, int height);
void	free_tetri(t_tet *tetri);
t_list	*free_list(t_list *list);
void	free_map(t_map *map);
int		ft_lstcount(t_list *list);
void	print_map(t_map *map);
t_map	*new_map(int size);
void	alter_map(t_tet *tetri, t_map *map, t_vec *pos, char c);
int		redundant_move(t_tet *tetri, int x, int y);
void	update_glst(char c, int x, int y);
int		evaluate_position(t_tet *tetri, t_map *map, int x, int y);
int		solve_map(t_map *map, t_list *list);
t_map	*init_solver(t_list *list);
int		sqrt_ceiling(int n);
t_tet	*new_tetri(char **pos, int w, int h, char c);
int		block_continuity(char *str);
void	get_limits(char *str, t_vec *min, t_vec *max);
int		is_valid_input(char *str, int size_read);
t_tet	*get_tetri(char *str, char c);
t_vec	*new_vector(int x, int y);
t_list	*read_source(int fd);

#endif
