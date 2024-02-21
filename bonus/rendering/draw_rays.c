/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:12:57 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 14:46:53 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	drawlinedda(t_game *game, t_pos *player, int i, int color)
{
	double	dx;
	double	dy;
	double	steps;
	double	x;
	double	y;

	if (fabs(game->wall[i].x - player->x) > fabs(game->wall[i].y - player->y))
		steps = fabs(game->wall[i].x - player->x);
	else
		steps = fabs(game->wall[i].y - player->y);
	dx = (game->wall[i].x - player->x) / steps;
	dy = (game->wall[i].y - player->y) / steps;
	x = WINDOW_WEIGHT / 2;
	y = WINDOW_HEIGHT / 2;
	i = 0;
	while (i <= steps)
	{
		if (pow(x - WINDOW_WEIGHT / 2, 2) + pow(y - WINDOW_HEIGHT / 2,
				2) >= pow((((WINDOW_HEIGHT + WINDOW_WEIGHT) / 2) / 2.36), 2))
			break ;
		my_mlx_pixel_put(game->image, (int)(x / 5), (int)(y / 5), color);
		x += dx;
		y += dy;
		i++;
	}
}

void	draw_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < WINDOW_WEIGHT)
	{
		drawlinedda(game, game->pixel_player, i, 0xFF0000);
		i++;
	}
}
