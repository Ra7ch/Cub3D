/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:59:09 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/11/14 21:56:59 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_count_world(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if ((str[i] != ' ' && str[i] != '\t') && str[i])
			count++;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
			i++;
	}
	return (count);
}

char	**ft_spl(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc((ft_count_world(str) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (*str && *str != '\n')
	{
		while (*str == '\t' || *str == ' ')
			str++;
		while (str[i] != '\t' && str[i] != ' ' && str[i] && str[i] != '\n')
			i++;
		if (i)
		{
			tab[j] = ft_substr(str, 0, i);
			str = (str + i);
			j++;
		}
		i = 0;
	}
	tab[j] = NULL;
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen - 1 < start || slen == 0)
		return (ft_strdup(""));
	if (slen - (size_t)start < len)
		len = slen - (size_t)start;
	str = malloc(len + 1);
	if (!str)
		return (0);
	while ((s + start)[i] && i < len)
	{
		str[i] = (s + start)[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_atoi_check(char *str)
{
	int			i;
	int			sign;
	long long	n;

	n = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (-1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i] && str[i + 1])
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		n = n * 10 + (str[i++] - '0');
		if ((n * sign) > INT32_MAX || (n * sign) < INT32_MIN)
			return (-1);
	}
	return (n * sign);
}
