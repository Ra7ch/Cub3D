/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:54:36 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/11/14 21:57:56 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	msg_error(int i)
{
	ft_putstr_fd("\x1B[31m \x1B[1m ERROR:\x1B[0m", 2);
	if (i == 0)
		ft_putstr_fd("\x1B[1m [BAD_FILE]", 2);
	else if (i == 1)
		ft_putstr_fd("\x1B[1m [BAD_TEXTURE]", 2);
	else if (i == 2)
		ft_putstr_fd("\x1B[1m [BAD_SYNTAX]", 2);
	else if (i == 3)
		ft_putstr_fd("\x1B[1m [BAD_MAP]", 2);
	else
		ft_putstr_fd("\x1B[1m [invalid number of arguments]", 2);
	exit(1);
}

int	ft_initializ_fd(t_data *data, char **tab)
{
	if (open(tab[1], O_RDONLY) == -1 || open(tab[1], __O_DIRECTORY) != -1)
		return (-1);
	if (!ft_strcmp(tab[0], "NO"))
		data->textur.no = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "SO"))
		data->textur.so = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "WE"))
		data->textur.we = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[0], "EA"))
		data->textur.ea = ft_strdup(tab[1]);
	return (0);
}

int	ft_initializ_color(t_data *data, char **tab)
{
	int		i;
	char	*str;
	int		rgb;

	i = 1;
	str = NULL;
	while (tab && tab[i])
	{
		str = ft_strjoin(str, tab[i]);
		if (i > 1 && ft_isdigit(tab[i - 1][ft_strlen(tab[i - 1]) - 1])
			&& tab[i][0])
			return (free(str), -1);
		i++;
	}
	rgb = check_color(str);
	free(str);
	if (rgb == -1)
		return (1);
	if (!ft_strcmp(tab[0], "F"))
		data->textur.floor = rgb;
	else
		data->textur.ceil = rgb;
	return (0);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (str[i] == 0 || str[i] == '\n');
}

void	ft_free(char **arg)
{
	int	i;

	i = 0;
	if (arg)
	{
		while (arg && arg[i])
			i++;
		while (i)
			free(arg[--i]);
		free(arg);
		arg = NULL;
	}
}
