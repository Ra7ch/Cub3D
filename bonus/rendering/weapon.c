/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:58:10 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/12 14:50:24 by raitmous         ###   ########.fr       */
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
	weapontexturex = (x - weaponx) * game->animation[game->g].w / (WINDOW_WEIGHT
			/ 1.9);
	weapontexturey = (y - weapony) * game->animation[game->g].h / (WINDOW_HEIGHT
			/ 1.66);
	game->animation[game->g].x = weapontexturex
		% (int)game->animation[game->g].w;
	game->animation[game->g].y = weapontexturey
		% (int)game->animation[game->g].h;
	color = get_texture_color(&(game->animation[game->g]),
			(int)(game->animation[game->g].x),
			(int)(game->animation[game->g].y));
	return (color);
}

void	draw_weapon(t_game *game, int x, int y)
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
		if (game->g == 34 || game->shoot_c == 0)
			game->g = 1;
		if (game->shoot_c > game->g * 1)
			game->g++;
		color = get_weapon_color(game, x, y);
		if ((unsigned int)color != 0xff000000 && color != 0x00FF00)
			my_mlx_pixel_put(game->image, x * (WINDOW_WEIGHT / NUM_RAYS), y,
				color);
	}
}
