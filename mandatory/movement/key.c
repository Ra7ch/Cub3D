/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:28:46 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 04:03:15 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

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
	if (keycode == 65307)
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
