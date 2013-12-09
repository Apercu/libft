/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:06:46 by bgronon           #+#    #+#             */
/*   Updated: 2013/11/30 12:00:05 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s && f)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		while (s[i] != '\0')
		{
			if (f != NULL)
				str[i] = f(i, (char)(s[i]));
			else
				str[i] = s[i];
			i++;
		}
	}
	return (str);
}
