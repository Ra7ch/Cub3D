/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:01:33 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/11/14 23:15:46 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_and_open(char *filename, char *format)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd != -1)
		msg_error(0);
	if (!ft_strncmp(&filename[ft_strlen(filename) - 4], format, 4))
		fd = open(filename, O_RDONLY);
	if (fd == -1)
		msg_error(0);
	return (fd);
}

int	ft_check_line_map(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& (str[i] != '\n'))
			return (1);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			if (data->map.player.pos != -1)
				return (1);
			data->map.player.pos = str[i];
		}
		i++;
	}
	return (0);
}

int	check_color_line(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i] && c <= 2)
	{
		if (str[i] == ',')
		{
			if (i == 0 || !str[i + 1] || str[i + 1] == ',')
				return (-1);
			c++;
		}
		else if (!ft_isdigit(str[i]) && str[i] != '+')
			return (-1);
		i++;
	}
	if (c != 2)
		return (-1);
	return (0);
}

int	check_color(char *str)
{
	int		rgb[3];
	char	**tab;

	if (check_color_line(str))
		return (-1);
	tab = ft_split(str, ',');
	rgb[0] = ft_atoi_check(tab[0]);
	rgb[1] = ft_atoi_check(tab[1]);
	rgb[2] = ft_atoi_check(tab[2]);
	ft_free(tab);
	if (rgb[0] >= 0 && rgb[0] <= 255 && rgb[1] >= 0 && rgb[1] <= 255
		&& rgb[2] >= 0 && rgb[2] <= 255)
		return (rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2]);
	return (-1);
}

int	ft_check_line(char **tab, t_data *data, int *check)
{
	t_textur	*tr;

	tr = &data->textur;
	if (tab && *tab)
	{
		if (((!ft_strcmp(tab[0], "NO") && tr->no == NULL) || (!ft_strcmp(tab[0],
						"SO") && tr->so == NULL) || (!ft_strcmp(tab[0], "WE")
					&& tr->we == NULL) || (!ft_strcmp(tab[0], "EA")
					&& tr->ea == NULL)) && tab[1] && !tab[2])
			return ((*check)++, ft_initializ_fd(data, tab));
		else if (((!ft_strcmp(tab[0], "F") && tr->floor == -1)
				|| (!ft_strcmp(tab[0], "C") && tr->ceil == -1)) && tab[1])
			return ((*check)++, ft_initializ_color(data, tab));
		else
			return (1);
	}
	return (0);
}
