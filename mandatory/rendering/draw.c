/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:22:40 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 02:03:43 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

// hadi khass nfree fiha mazal f lexits.
t_image	*create_image(void *mlx_ptr, int width, int height)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
	{
		printf("Error: Failed to allocate memory for the image.\n");
		exit(EXIT_FAILURE);
	}
	img->img = mlx_new_image(mlx_ptr, width, height);
	if (!img->img)
	{
		printf("Error: Failed to create image.\n");
		free(img);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		printf("Error: Failed to get image data address.\n");
		mlx_destroy_image(mlx_ptr, img->img);
		free(img);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WEIGHT || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	drawall(t_game *game)
{
	ft_controls(game);
	if (game->intro_lock)
	{
		mlx_clear_window(game->mlx, game->win);
		raycast(game->pixel_player, game, game->direction);
		render3dscene(game);
		mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
		mlx_destroy_image(game->mlx, game->image->img);
		free(game->image);
		game->image = create_image(game->mlx, WINDOW_WEIGHT, WINDOW_HEIGHT);
		game->intro_lock = 0;
	}
	return (0);
}
