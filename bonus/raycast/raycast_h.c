/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:17 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 23:28:03 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_pos	*raycastx_2(t_game *game, t_pos *collision, double xstep, double ystep)
{
	int	x;
	int	y;

	x = (int)(collision->x / game->xtile);
	y = (int)(collision->y / game->ytile);
	while (collision->y < game->height * game->ytile && collision->y >= 0
		&& collision->x < game->len[y] * game->ytile
		&& collision->x >= 0)
	{
		if (y >= game->height || x >= game->len[y])
			break ;
		if (game->map[y][x] == '1' || (y - 1 >= 0 && x < game->len[y
					- 1] && game->map[y - 1][x] == '1')
			|| game->map[y][x] == CLOSED_DOOR || (y - 1 >= 0
				&& x < game->len[y - 1] && game->map[y
				- 1][x] == CLOSED_DOOR))
			return (collision);
		collision->x += xstep;
		collision->y += ystep;
		x = (int)(collision->x / game->xtile);
		y = (int)(collision->y / game->ytile);
	}
	return (free(collision), NULL);
}

t_pos	*raycastx(t_pos *player, t_game *game, double rayAngle)
{
	t_pos	*collision;
	double	xstep;
	double	ystep;

	collision = malloc(sizeof(t_pos));
	if (sin(rayAngle) > 0)
		collision->y = (int)(player->y / game->ytile) * game->ytile;
	else
		collision->y = (int)(player->y / game->ytile) * game->ytile
			+ game->ytile;
	collision->x = player->x + (player->y - collision->y) / tan(rayAngle);
	if (cos(rayAngle) > 0)
		xstep = fabs(game->ytile / tan(rayAngle));
	else
	{
		xstep = game->ytile / tan(rayAngle);
		if (sin(rayAngle) < 0)
			xstep *= -1;
	}
	if (sin(rayAngle) > 0)
		ystep = -game->ytile;
	else
		ystep = game->ytile;
	return (raycastx_2(game, collision, xstep, ystep));
}
