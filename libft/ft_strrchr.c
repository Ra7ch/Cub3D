/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:02:17 by raitmous          #+#    #+#             */
/*   Updated: 2023/09/01 02:57:48 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	if (!(c <= 255 && c >= 0))
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
