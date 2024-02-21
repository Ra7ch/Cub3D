/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:19:49 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/11/17 21:42:52 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initializ(t_data *data)
{
	t_textur	textur;
	t_mape		map;
	t_player	player;

	map.map = NULL;
	map.width = 0;
	map.height = 0;
	map.player.x = -1;
	map.player.y = -1;
	textur.so = NULL;
	textur.we = NULL;
	textur.no = NULL;
	textur.ea = NULL;
	textur.floor = -1;
	textur.ceil = -1;
	player.pos = -1;
	player.dir = 0;
	data->map = map;
	data->map.player = player;
	data->textur = textur;
}

void	check_line(t_data *data, char *str, char **temp, int *check)
{
	char	**tab;

	if (*check != 6)
	{
		tab = ft_spl(str);
		if (tab && *tab && ft_check_line(tab, data, check))
			(free(str), ft_free(tab), msg_error(2));
		ft_free(tab);
	}
	else
	{
		if (ft_check_space(str) && !*temp)
			return ;
		else if (ft_check_line_map(data, str) || ft_check_space(str))
		{
			if (temp && *temp)
				free(*temp);
			(free(str), msg_error(3));
		}
		else
			*temp = ft_strjoin(*temp, str);
	}
}

int	ft_check_map(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->map.player.pos == -1)
		return (1);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != ' ' && (tab[i][j] == '0' || tab[i][j] == 'N'
					|| tab[i][j] == 'S' || tab[i][j] == 'W' || tab[i][j] == 'E'
					|| tab[i][j] == 'F' || tab[i][j] == 'O') && (!tab[i + 1]
					|| i == 0 || (ft_strlen(tab[i - 1]) - 1) < j
					|| (ft_strlen(tab[i + 1]) - 1) < j || tab[i][j + 1] == ' '
					|| !tab[i][j + 1] || tab[i][j - 1] == ' ' || tab[i
					- 1][j] == ' ' || tab[i + 1][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_and_lead(int fd, t_data *data)
{
	char	*str;
	char	*temp;
	int		check;

	temp = NULL;
	check = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		check_line(data, str, &temp, &check);
		free(str);
	}
	if (!temp || temp[ft_strlen(temp) - 1] == '\n')
	{
		if (temp)
			free(temp);
		msg_error(2);
	}
	data->map.map = ft_split(temp, '\n');
	free(temp);
}

t_data	parsing(int ac, char **av)
{
	t_data	data;

	ft_initializ(&data);
	if (ac == 2)
	{
		ft_check_and_lead(check_and_open(av[1], ".cub"), &data);
		if (ft_check_map(data.map.map, &data))
			msg_error(3);
	}
	else
		msg_error(4);
	return (data);
}
