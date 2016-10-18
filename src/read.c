/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 00:40:30 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/11 00:44:34 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*read_source(int fd)
{
	char	*buf;
	int		size_read;
	t_tet	*tetri;
	t_list	*list;
	char	c;

	buf = ft_strnew(21);
	list = NULL;
	c = 'A';
	while ((size_read = read(fd, buf, 21)) >= 20)
	{
		if (!(is_valid_input(buf, size_read)) ||
				(tetri = get_tetri(buf, c)) == NULL || ++c > 'Z')
			return (free_list(list));
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
		ft_lstadd(&g_list, ft_lstnew(tetri, sizeof(t_tet)));
	}
	ft_strdel(&buf);
	if (size_read != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
