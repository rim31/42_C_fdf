/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:12:53 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:13:29 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				mlx_pixel_put_to_image(int x, int y, t_env *e)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (e->dr.color & 0xFF0000) >> 16;
	g = (e->dr.color & 0xFF00) >> 8;
	r = (e->dr.color & 0xFF);
	if (y > 0 && x > 0 && x < 2000 && y < 1000)
	{
		e->dr.data[y * e->dr.size_line + x * e->dr.bpp / 8] = r;
		e->dr.data[y * e->dr.size_line + x * e->dr.bpp / 8 + 1] = g;
		e->dr.data[y * e->dr.size_line + x * e->dr.bpp / 8 + 2] = b;
	}
}
