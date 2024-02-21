/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knife.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:42:40 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 14:52:08 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	get_weapon_color(t_game *game, int x, int y)
{
	int	weaponx;
	int	weapony;
	int	weapontexturex;
	int	weapontexturey;
	int	color;

	weaponx = (((WINDOW_WEIGHT / 4)));
	weapony = WINDOW_HEIGHT - (WINDOW_HEIGHT / 1.66);
	weapontexturex = (x - weaponx) * game->knife[game->knife_id].w
		/ (WINDOW_WEIGHT / 1.9);
	weapontexturey = (y - weapony) * game->knife[game->knife_id].h
		/ (WINDOW_HEIGHT / 1.66);
	game->knife[game->knife_id].x = weapontexturex
		% (int)game->knife[game->knife_id].w;
	game->knife[game->knife_id].y = weapontexturey
		% (int)game->knife[game->knife_id].h;
	color = get_texture_color(&(game->knife[game->knife_id]),
			(int)(game->knife[game->knife_id].x),
			(int)(game->knife[game->knife_id].y));
	return (color);
}

void	draw_knife(t_game *game, int x, int y)
{
	int	weaponwidth;
	int	weaponheight;
	int	weaponx;
	int	weapony;
	int	color;

	weaponwidth = WINDOW_WEIGHT / 1.9;
	weaponheight = WINDOW_HEIGHT / 1.66;
	weaponx = (((WINDOW_WEIGHT / 4)));
	weapony = WINDOW_HEIGHT - weaponheight;
	if (x >= weaponx && x < weaponx + weaponwidth && y >= weapony && y < weapony
		+ weaponheight)
	{
		if (game->knife_id == 69 || game->shoot_c == 0)
			game->knife_id = 1;
		if (game->shoot_c > game->knife_id * 1)
			game->knife_id++;
		color = get_weapon_color(game, x, y);
		if ((unsigned int)color != 0xffffff
			&& (unsigned int)color != 0xff000000)
			my_mlx_pixel_put(game->image, x * (WINDOW_WEIGHT / NUM_RAYS), y,
				color);
	}
}

void	draw_knife_attack_1(t_game *game, int x, int y)
{
	int	weaponwidth;
	int	weaponheight;
	int	weaponx;
	int	weapony;
	int	color;

	weaponwidth = WINDOW_WEIGHT / 1.9;
	weaponheight = WINDOW_HEIGHT / 1.66;
	weaponx = (((WINDOW_WEIGHT / 4)));
	weapony = WINDOW_HEIGHT - weaponheight;
	if (x >= weaponx && x < weaponx + weaponwidth && y >= weapony && y < weapony
		+ weaponheight)
	{
		if (game->knife_id == 110 || game->shoot_c == 69)
			game->knife_id = 70;
		if (game->shoot_c > game->knife_id * 1)
			game->knife_id++;
		color = get_weapon_color(game, x, y);
		if ((unsigned int)color != 0xff000000)
			my_mlx_pixel_put(game->image, x * (WINDOW_WEIGHT / NUM_RAYS), y,
				color);
	}
}
