/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:43:36 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 16:43:50 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_struntil(char *str, char *stop)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_strncmp(str + i, stop, ft_strlen(stop)))
			return (ft_strsub(str, 0, i));
		++i;
	}
	return (NULL);
}
