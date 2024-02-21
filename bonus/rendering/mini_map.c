/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:41:32 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 23:29:25 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	handlebackgroundcolors(char mapChar, int a, int b)
{
	if (a <= 10 && a >= -10 && b <= 10 && b >= -10)
		return (0x000000);
	if (mapChar == '1')
		return (0x000FFF);
	if (mapChar == CLOSED_DOOR)
		return (0x043418);
	if (mapChar == OPENED_DOOR)
		return (0x339966);
	return (0xFFFFFF);
}

int	check_minimap(t_game *game, int px, int py)
{
	if ((int)(px / game->xtile) < 0 || (int)(py / game->ytile) < 0 || (int)(py
			/ game->ytile) >= game->height || (int)(px
			/ game->xtile) >= game->len[(int)(py / game->ytile)]
		|| !ft_strchr("01NSWEFO", game->map[(int)(py / game->ytile)][(int)(px
				/ game->xtile)]))
		return (1);
	return (0);
}

void	draw_background_2(t_game *game, int b, double playerx, double playery)
{
	int		a;
	double	px;
	double	py;
	int		color;

	a = (((WINDOW_HEIGHT + WINDOW_WEIGHT) / 2) / 2.36) * -1;
	while (a <= (((WINDOW_HEIGHT + WINDOW_WEIGHT) / 2) / 2.36))
	{
		px = playerx + a;
		py = playery + b;
		if (check_minimap(game, px, py))
		{
			a++;
			continue ;
		}
		color = handlebackgroundcolors(game->map[(int)(py
					/ game->ytile)][(int)(px / game->xtile)], a, b);
		if (pow(px - playerx, 2) + pow(py - playery, 2) <= pow((((WINDOW_HEIGHT
							+ WINDOW_WEIGHT) / 2) / 2.36), 2))
			my_mlx_pixel_put(game->image, (int)((WINDOW_WEIGHT / 2 + a) / 5),
				(int)((WINDOW_HEIGHT / 2 + b) / 5), color);
		a++;
	}
}

void	draw_background(t_game *game)
{
	int	b;

	b = (((WINDOW_HEIGHT + WINDOW_WEIGHT) / 2) / 2.36) * -1;
	while (b <= (((WINDOW_HEIGHT + WINDOW_WEIGHT) / 2) / 2.36))
	{
		draw_background_2(game, b, (double)(game->player->x * game->xtile),
			(double)(game->player->y * game->ytile));
		b++;
	}
}
