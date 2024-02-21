/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:15 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 23:34:49 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_pos	*raycasty_2(t_game *game, t_pos collision, double xstep, double ystep)
{
	int		x;
	int		y;
	t_pos	*c;

	x = (int)(collision.x / game->xtile);
	y = (int)(collision.y / game->ytile);
	c = NULL;
	while (collision.y < game->height * game->ytile && collision.y >= 0
		&& collision.x < game->len[y] * game->ytile
		&& collision.x >= 0)
	{
		if (y >= game->height || x >= game->len[y])
			break ;
		if (game->map[y][x] == '1' || (x - 1 >= 0 && game->map[y][x
				- 1] == '1'))
		{
			c = malloc(sizeof(t_pos));
			return (c->x = collision.x, c->y = collision.y, c);
		}
		collision.x += xstep;
		collision.y += ystep;
		x = (int)(collision.x / game->xtile);
		y = (int)(collision.y / game->ytile);
	}
	return (c);
}

t_pos	*raycasty(t_pos *player, t_game *game, double rayangle)
{
	t_pos	collision;
	double	xstep;
	double	ystep;

	if (cos(rayangle) <= 0)
		collision.x = (int)(player->x / game->xtile) * game->xtile;
	else
		collision.x = (int)(player->x / game->xtile) * game->xtile
			+ game->xtile;
	collision.y = player->y + (player->x - collision.x) * tan(rayangle);
	if (sin(rayangle) <= 0)
		ystep = fabs(game->xtile * tan(rayangle));
	else
	{
		ystep = game->xtile * tan(rayangle);
		if (cos(rayangle) >= 0)
			ystep *= -1;
	}
	if (cos(rayangle) <= 0)
		xstep = -game->xtile;
	else
		xstep = game->xtile;
	return (raycasty_2(game, collision, xstep, ystep));
}
