/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:48:50 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:45:01 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	distance(t_pos *point1, t_pos *point2)
{
	double	dx;
	double	dy;

	dx = point2->x - point1->x;
	dy = point2->y - point1->y;
	return (sqrt(dx * dx + dy * dy));
}

t_pos	*chooseclosestcollision(t_pos *collisiony, t_pos *collisionx,
		t_game *game, int i)
{
	double	distancey;
	double	distancex;

	if (collisiony == NULL && collisionx == NULL)
		return (NULL);
	if (collisiony == NULL)
	{
		game->wall[i].side = HORIZONTAL;
		return (collisionx);
	}
	if (collisionx == NULL)
	{
		game->wall[i].side = VERTICAL;
		return (collisiony);
	}
	distancey = distance(game->pixel_player, collisiony);
	distancex = distance(game->pixel_player, collisionx);
	if (distancey < distancex)
	{
		game->wall[i].side = VERTICAL;
		return (free(collisionx), collisiony);
	}
	game->wall[i].side = HORIZONTAL;
	return (free(collisiony), collisionx);
}

void	fill_wall_orientation(t_game *game, double rayangle, int i)
{
	if (sin(rayangle) < 0 && game->wall[i].side == VERTICAL)
		game->wall[i].orientation = SOUTH;
	if (cos(rayangle) < 0 && game->wall[i].side == HORIZONTAL)
		game->wall[i].orientation = WEST;
	if (cos(rayangle) > 0 && game->wall[i].side == HORIZONTAL)
		game->wall[i].orientation = EAST;
	if (sin(rayangle) > 0 && game->wall[i].side == VERTICAL)
		game->wall[i].orientation = NORTH;
}

void	fill_wall_detail(t_game *game, int i, t_pos *player, t_pos *collision)
{
	double	distanc;
	double	corrected_ditance;
	double	angledifference;
	double	rayangle;

	rayangle = game->direction - M_PI / 6 + (i * (double)((FOV_DEGREES / 3)
				/ NUM_RAYS));
	game->wall[i].x = (int)collision->x;
	game->wall[i].y = (int)collision->y;
	distanc = distance(player, collision);
	game->wall[i].distance = distanc;
	angledifference = fabs(game->direction - rayangle);
	if (angledifference < M_PI / 2)
		corrected_ditance = distanc * cos(angledifference);
	else
		corrected_ditance = distanc * cos(M_PI - angledifference);
	game->wall[i].distance = corrected_ditance;
	game->wall[i].pixel = i;
	game->wall[i].height = (int)((64 * WINDOW_WEIGHT) / corrected_ditance);
	game->wall[i].top = (WINDOW_HEIGHT - (game->wall[i].height
				* SCALING_FACTOR)) / 2;
	game->wall[i].bottom = game->wall[i].top + (game->wall[i].height
			* SCALING_FACTOR);
	fill_wall_orientation(game, rayangle, i);
	free(collision);
}

void	raycast(t_pos *player, t_game *game, double playerDirection)
{
	t_pos	*collisionx;
	t_pos	*collisiony;
	t_pos	*collision;
	double	rayangle;
	int		i;

	i = 0;
	collision = NULL;
	collisionx = NULL;
	collisiony = NULL;
	while (i < NUM_RAYS)
	{
		rayangle = playerDirection - M_PI / 6 + (i * (double)((FOV_DEGREES / 3)
					/ NUM_RAYS));
		collisionx = raycastx(player, game, rayangle);
		collisiony = raycasty(player, game, rayangle);
		collision = chooseclosestcollision(collisionx, collisiony, game, i);
		if (collision != NULL)
			fill_wall_detail(game, i, player, collision);
		i++;
	}
}
