/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 19:43:08 by bgronon           #+#    #+#             */
/*   Updated: 2013/12/09 19:45:54 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static t_list	*ft_getnode(int fd, t_list **save)
{
	t_list	*new;
	t_node	*test;

	while (*save)
	{
		if (((t_node *) (*save)->content)->fd == fd)
			return (*save);
		*save = (*save)->next;
	}
	test = (t_node *) malloc(sizeof(t_node));
	if (!test)
		return (NULL);
	test->remind = NULL;
	test->fd = fd;
	new = ft_lstnew(test, sizeof(t_node));
	ft_lstadd(save, new);
	free(test);
	return (ft_getnode(fd, save));
}

static int		ft_testremind(t_list *current, char **line)
{
	int		index;

	if (REMIND->remind)
	{
		index = ft_indexof(REMIND->remind, '\n');
		if (index != -1)
		{
			*line = ft_strsub(REMIND->remind, 0, index);
			REMIND->remind += index + 1;
			return (1);
		}
	}
	return (0);
}

static int		ft_createrem(t_list *current, char **line, char *buff, int ret)
{
	int		index;

	buff[ret] = '\0';
	REMIND->remind = (REMIND->remind) ? REMIND->remind : ft_strdup("");
	REMIND->remind = ft_strjoin(REMIND->remind, buff);
	index = ft_indexof(REMIND->remind, '\n');
	if (index != -1)
	{
		*line = ft_strsub(REMIND->remind, 0, index);
		REMIND->remind += index + 1;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*save;
	t_list			*current;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	current = ft_getnode(fd, &save);
	if (fd < 0 || BUFF_SIZE < 1 || !current)
		return (-1);
	if (ft_testremind(current, line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if (ft_createrem(current, line, buff, ret))
			return (1);
	}
	if (REMIND->remind)
	{
		*line = ft_strdup(REMIND->remind);
		free(current);
		REMIND->remind = NULL;
		return (1);
	}
	return (0);
}
