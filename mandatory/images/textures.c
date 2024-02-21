/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:29:06 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:37:52 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

void	ft_free_images(t_game *game)
{
	int	t;

	t = 0;
	mlx_destroy_image(game->mlx, game->image->img);
	free(game->image);
	while (t <= 3)
	{
		mlx_destroy_image(game->mlx, game->textures[t].img);
		t++;
	}
}

void	texture_init(t_game *game, t_image *tx, char *path)
{
	tx->img = mlx_xpm_file_to_image(game->mlx, path, &(tx->w), &(tx->h));
	if (!tx->img)
	{
		ft_putstr_fd("error: texture '", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("' not found.\n", 2);
		exit(0);
	}
	tx->addr = mlx_get_data_addr(tx->img, &(tx->bits_per_pixel),
			&(tx->line_length), &(tx->endian));
	tx->x = 0;
	tx->y = 0;
}

void	initialise_images(t_game *game)
{
	texture_init(game, &game->textures[0], game->texture.no);
	texture_init(game, &game->textures[1], game->texture.so);
	texture_init(game, &game->textures[2], game->texture.we);
	texture_init(game, &game->textures[3], game->texture.ea);
}
