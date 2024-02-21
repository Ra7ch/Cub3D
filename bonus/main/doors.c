/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:32 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/10 10:50:31 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	count_doors(t_game *game)
{
	int	y;
	int	i;
	int	x;

	y = 0;
	i = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == CLOSED_DOOR)
			{
				i++;
			}
			x++;
		}
		y++;
	}
	return (i);
}

void	fill_door(t_game *game)
{
	int	x;
	int	y;
	int	i;

	game->d = malloc(sizeof(t_door) * (count_doors(game) + 1));
	y = 0;
	i = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == CLOSED_DOOR)
			{
				game->d[i].x = x;
				game->d[i].y = y;
				game->d[i].status = CLOSE;
				game->d[i].door = 25;
				i++;
			}
			x++;
		}
		y++;
	}
	game->door_number = i;
}
