/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:10:24 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/05 14:48:25 by ahunt            ###   ########.fr       */
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

typedef struct			s_grid
{
	char		**map;
	int			size;
}    					t_grid;

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
}						t_tet;

int		main(int argc, char **argv);
t_list	*read_source(int fd);

#endif
