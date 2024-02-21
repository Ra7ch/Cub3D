/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:26:41 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/13 13:22:00 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	mouse_motion_hook(int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (x <= WINDOW_WEIGHT && x >= 0 && y <= WINDOW_HEIGHT && y >= 0)
	{
		if (game->mouse_x > x)
			game->direction += x * 0.00003;
		else
			game->direction += -x * 0.00003;
		game->intro_lock = 1;
	}
	game->mouse_x = x;
	game->mouse_y = y;
	return (0);
}
