/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:33:49 by raitmous          #+#    #+#             */
/*   Updated: 2022/12/11 23:44:01 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(t_vector *content)
{
	t_lst	*i;

	i = (t_lst *)malloc(sizeof(t_lst));
	if (!i)
		return (0);
	i->dem = content;
	i->next = 0;
	return (i);
}
