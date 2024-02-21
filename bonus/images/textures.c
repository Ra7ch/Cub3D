/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:29:06 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/16 23:48:54 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

void	ft_free_images(t_game *game)
{
	int	t;

	mlx_destroy_image(game->mlx, game->image->img);
	free(game->image);
	t = 1;
	while (t <= 34)
	{
		mlx_destroy_image(game->mlx, game->animation[t].img);
		t++;
	}
	t = 1;
	while (t <= 110)
	{
		mlx_destroy_image(game->mlx, game->knife[t].img);
		t++;
	}
	t = 0;
	while (t <= 4)
	{
		mlx_destroy_image(game->mlx, game->textures[t].img);
		t++;
	}
}

void	texture_init(t_game *game, t_image *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &(texture->w),
			&(texture->h));
	if (!texture->img)
	{
		ft_putstr_fd("error: texture '", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("' not found.\n", 2);
		exit(0);
	}
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel),
			&(texture->line_length), &(texture->endian));
	texture->x = 0;
	texture->y = 0;
}

void	animation_sprite(t_game *game)
{
	int		t;
	char	*str;
	char	*_t;

	t = 1;
	while (t <= 34)
	{
		_t = ft_itoa(t);
		if (t <= 9)
			str = ft_strjoin2("assets/animation_doom/DOOM_out000", _t);
		else
			str = ft_strjoin2("assets/animation_doom/DOOM_out00", _t);
		free(_t);
		_t = ft_strjoin2(str, ".xpm");
		free(str);
		texture_init(game, &game->animation[t], _t);
		free(_t);
		t++;
	}
	game->doom = 0;
	game->g = 1;
}

void	knife_sprite(t_game *game)
{
	int		t;
	char	*str;
	char	*_t;

	t = 1;
	while (t <= 110)
	{
		_t = ft_itoa(t);
		str = ft_strjoin2("assets/knife2/", _t);
		free(_t);
		_t = ft_strjoin2(str, ".xpm");
		free(str);
		texture_init(game, &game->knife[t], _t);
		free(_t);
		t++;
	}
	game->knif = 0;
	game->knife_id = 1;
	game->knifeattack1 = 0;
}

void	initialise_images(t_game *game)
{
	texture_init(game, &game->textures[0], game->texture.no);
	texture_init(game, &game->textures[1], game->texture.so);
	texture_init(game, &game->textures[2], game->texture.we);
	texture_init(game, &game->textures[3], game->texture.ea);
	texture_init(game, &game->textures[4], "assets/doors/door6.xpm");
	animation_sprite(game);
	knife_sprite(game);
}
