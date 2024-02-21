/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:16:11 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:08:27 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_pos	*ft_player(t_game *game, char c, int x, int y)
{
	t_pos	*player;

	player = malloc(sizeof(t_pos));
	player->x = x + 0.5;
	player->y = y + 0.5;
	if (c == 'S')
		game->direction = -M_PI / 2;
	else if (c == 'N')
		game->direction = M_PI / 2;
	else if (c == 'W')
		game->direction = M_PI;
	else if (c == 'E')
		game->direction = 0;
	return (player);
}

t_pos	*find_player(char **map, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'S')
				return (ft_player(game, map[y][x], x, y));
			else if (map[y][x] == 'N')
				return (ft_player(game, map[y][x], x, y));
			else if (map[y][x] == 'W')
				return (ft_player(game, map[y][x], x, y));
			else if (map[y][x] == 'E')
				return (ft_player(game, map[y][x], x, y));
			x++;
		}
		y++;
	}
	return (NULL);
}
