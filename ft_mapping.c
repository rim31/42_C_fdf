/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:54:53 by oseng             #+#    #+#             */
/*   Updated: 2016/02/12 04:04:02 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**open the new window for drawing pixel, inialize mlx_init
**name the mlx_new_window with previous ptr, size, and nickname
**draw image and not pixel_put. Better result mlx_hook for repeat keys,
** the mlx_loop waiting for input than mlx_key_hook
*/

static int	my_mouse_funct(int button, int x, int y, t_env *e)
{
	if (button == 1)
		e->zdeg += 0.05;
	if (button == 2)
		e->zdeg -= 0.05;
	if (button == 3)
	{
		if (e->xdeg != 0)
			e->xdeg = 0;
		else
			e->xdeg = x * y;
	}
	mlx_destroy_image(e->mlx, e->image);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	ft_draw(e);
	return (0);
}

t_env		ft_mapping(t_env a)
{
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 2000, 1000, "mlx 42");
	ft_draw(&a);
	mlx_mouse_hook(a.win, my_mouse_funct, &a);
	mlx_hook(a.win, 2, 0, my_key_funct, &a);
	mlx_loop(a.mlx);
	return (a);
}
