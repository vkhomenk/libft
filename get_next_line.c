/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:56:44 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/07/11 15:20:24 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*def_list(t_list **save, int fd)
{
	t_list	*tmp;

	tmp = *save;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", 1)))
		return (NULL);
	ft_lstadd(save, tmp);
	tmp->content_size = fd;
	return (tmp);
}

static int		fill_line(t_list *lst, char **line)
{
	char	*nl;

	if (!(nl = ft_strchr((char*)lst->content, '\n')))
		return (0);
	if (!(*line = ft_strsub(lst->content, 0, nl - (char*)lst->content)))
		return (-1);
	ft_memmove(lst->content, nl + 1, ft_strlen(nl));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*save;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	t_list			*lst;
	int				cr;

	IFRET(!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) ||
	!(lst = def_list(&save, fd)), -1);
	cr = -2;
	while (1)
	{
		if (cr < 0 && (cr = fill_line(lst, line)))
			return (cr);
		IFRET((cr = read(fd, buf, BUFF_SIZE)) < 0, -1);
		if (cr == 0 && (*(char*)lst->content))
			buf[cr++] = '\n';
		else if (cr == 0)
			return (0);
		buf[cr] = 0;
		ft_strchr(buf, '\n') ? cr = -2 : 0;
		IFRET(!(str = ft_strjoin((char*)lst->content, buf)), -1);
		ft_memdel(&lst->content);
		lst->content = str;
	}
}
