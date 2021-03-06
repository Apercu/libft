/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:02:41 by bgronon           #+#    #+#             */
/*   Updated: 2014/01/15 22:03:30 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charin(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		++str;
	}
	return (0);
}
