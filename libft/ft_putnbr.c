/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:40:43 by raitmous          #+#    #+#             */
/*   Updated: 2022/12/06 00:21:30 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
	{
		ft_putchar(n + '0', fd);
	}
}
