/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:42:27 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:51:52 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** mlx_new_image : needs pointer of mlx_init window, and, size of the window
** mlx_get_data_adress : store data in the ptr of the image : there are ptr
** of adress image,  ** bit per pixel(transparency, red, green, blue), adresse
**o f size of line  ** (number  ** of line mulitiply by line) and endian 0 or 1
** RGB or BGR colours order
** mlx_put_image_to_window : needs ptr of mlx, window, image et the position
** in the window
*/

t_env	ft_draw(t_env *a)
{
	a->image = mlx_new_image(a->mlx, 2000, 1000);
	a->dr.data = mlx_get_data_addr(a->image, &a->dr.bpp,
		&a->dr.size_line, &a->dr.endian);
	a->j = 0;
	while (a->j < a->y)
	{
		a->i = 0;
		while (a->i < a->x)
		{
			if (a->i > 0)
				ft_linehoriz(*a);
			if (a->j > 0)
				ft_linevert(*a);
			a->i++;
		}
		a->j++;
	}
	mlx_put_image_to_window(a->mlx, a->win, a->image, 0, 0);
	return (*a);
}
