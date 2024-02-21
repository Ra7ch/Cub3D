/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:50:47 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/10 10:35:57 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	get_texture_color(t_image *texture, int x, int y)
{
	int				pixel_position;
	unsigned int	color;

	if (x < 0 || y < 0 || x >= texture->w || y >= texture->h)
		return (0);
	pixel_position = y * texture->line_length + x * (texture->bits_per_pixel
			/ 8);
	color = *(unsigned int *)(texture->addr + pixel_position);
	return (color);
}
