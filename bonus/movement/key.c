/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:28:46 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 04:00:03 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	door_handling2(t_game *game, int x, int y, int state)
{
	int	i;

	game->map[y][x] = state;
	i = 0;
	while (i < game->door_number)
	{
		if (game->d[i].x == x && game->d[i].y == y)
		{
			if (state == OPENED_DOOR)
			{
				game->d[i].status = OPEN;
				game->d[i].door = 26;
			}
			else
			{
				game->d[i].status = CLOSE;
				game->d[i].door = 60;
			}
		}
		i++;
	}
}

void	door_handling(t_game *game)
{
	int		x;
	int		y;
	double	range;
	double	angel;

	if (game->map[(int)game->player->y][(int)game->player->x] == OPENED_DOOR)
		return ;
	range = (int)((game->xtile + game->ytile) / 2);
	angel = game->direction;
	x = (int)(cos(angel) * range);
	y = (int)(sin(angel) * range);
	x = (int)((x + (int)game->pixel_player->x) / game->xtile);
	y = (int)(((int)game->pixel_player->y - y) / game->ytile);
	if (game->map[y][x] == CLOSED_DOOR)
		door_handling2(game, x, y, OPENED_DOOR);
	else if (game->map[y][x] == OPENED_DOOR)
		door_handling2(game, x, y, CLOSED_DOOR);
}

void	keyhandling(int keycode, t_game *game)
{
	if (keycode == KNIFELINUX || keycode == DOOMLINUX || keycode == ATTACKLINUX
		|| keycode == UNARMEDLINUX)
	{
		game->knif = 0;
		game->doom = 0;
		game->shoot_c = 0;
		game->shoot = 0;
		game->knifeattack1 = 0;
		game->knife_id = 0;
		if (keycode == KNIFELINUX)
		{
			game->knife_id = 1;
			game->knif = 1;
		}
		if (keycode == DOOMLINUX)
			game->doom = 1;
		if (keycode == ATTACKLINUX)
		{
			game->knifeattack1 = 1;
			game->knife_id = 70;
			game->shoot_c = 69;
		}
	}
}

int	onkeypress(int keycode, t_game *game)
{
	if (keycode == WLINUX)
		game->move_up = 1;
	else if (keycode == SLINUX)
		game->move_down = 1;
	else if (keycode == ALINUX)
		game->move_left = 1;
	else if (keycode == DLINUX)
		game->move_right = 1;
	if (keycode == LEFTLINUX)
		game->direction -= M_PI / 100;
	if (keycode == RIGHTLINUX)
		game->direction += M_PI / 100;
	if (game->direction == -2 * M_PI || game->direction == 2 * M_PI)
		game->direction = 0;
	if (keycode == FLINUX)
		door_handling(game);
	if (keycode == 32)
		game->shoot = 1;
	keyhandling(keycode, game);
	if (keycode == ESCLINUX)
		ft_exit(game);
	ft_controls(game);
	return (0);
}

int	onkeyrelease(int keycode, t_game *game)
{
	if (keycode == WLINUX)
	{
		game->move_up = 0;
	}
	else if (keycode == SLINUX)
	{
		game->move_down = 0;
	}
	else if (keycode == ALINUX)
	{
		game->move_left = 0;
	}
	else if (keycode == DLINUX)
	{
		game->move_right = 0;
	}
	return (0);
}
