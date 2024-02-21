/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:40:16 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/16 23:49:24 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	initialise_textures(t_game *game)
{
	game->textures[1].y = 0;
	game->textures[0].y = 0;
	game->textures[2].y = 0;
	game->textures[3].y = 0;
	game->textures[4].y = 0;
}

int	detect_texture_x(t_game *game, int i)
{
	int	t;

	t = 0;
	if (game->wall[i].orientation == WEST)
		t = 2;
	else if (game->wall[i].orientation == SOUTH)
		t = 1;
	else if (game->wall[i].orientation == EAST)
		t = 3;
	else if (game->wall[i].orientation == NORTH)
		t = 0;
	else if (game->wall[i].orientation == C_DOOR)
		t = 4;
	if (game->wall[i].side == VERTICAL)
		game->textures[t].x = (int)game->wall[i].x % (int)game->textures[t].w;
	else if (game->wall[i].side == HORIZONTAL)
		game->textures[t].x = (int)game->wall[i].y % (int)game->textures[t].w;
	if (game->textures[t].x >= game->textures[t].w)
		game->textures[t].x -= game->textures[t].w;
	return (t);
}

int	get_pixel_color(t_game *game, int i, int y, double gamewallheight)
{
	double	j;
	double	l;
	int		color;
	int		t;

	t = detect_texture_x(game, i);
	j = (double)game->textures[t].h / gamewallheight;
	l = game->textures[t].y;
	if (game->wall[i].height > WINDOW_HEIGHT)
		game->textures[t].y += j * (gamewallheight - WINDOW_HEIGHT) / 2;
	color = get_texture_color(&(game->textures[t]), (int)(game->textures[t].x),
			(int)(game->textures[t].y));
	game->textures[t].y = l;
	if (y < game->wall[i].top)
		color = game->texture.ceil;
	else if (y >= game->wall[i].bottom)
		color = game->texture.floor;
	else
		game->textures[t].y += j;
	return (color);
}

void	handle_strip(t_game *game, int i, int x)
{
	int		y;
	int		color;
	double	gamewallheight;

	gamewallheight = game->wall[i].height * SCALING_FACTOR;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		color = get_pixel_color(game, i, y, gamewallheight);
		my_mlx_pixel_put(game->image, x * (WINDOW_WEIGHT / NUM_RAYS), y, color);
		if (game->doom)
			draw_weapon(game, x, y);
		else if (game->knif)
			draw_knife(game, x, y);
		else if (game->knifeattack1)
			draw_knife_attack_1(game, x, y);
		y++;
	}
}

void	render3dscene(t_game *game)
{
	int	i;
	int	x;

	x = WINDOW_WEIGHT - 1;
	i = 0;
	while (i < NUM_RAYS)
	{
		initialise_textures(game);
		handle_strip(game, i, x);
		x--;
		i++;
	}
}
