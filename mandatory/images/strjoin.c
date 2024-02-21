/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:54:28 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:21:22 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

char	*ft_check_strjoin2(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (ft_check_strjoin2(s1, s2));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = 0;
	s1 = NULL;
	return (str);
}
