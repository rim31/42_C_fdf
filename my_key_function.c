/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:13:48 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:17:10 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int keycode, t_env *a)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		a->updown -= 10;
	if (keycode == 125)
		a->updown += 10;
	if (keycode == 123)
		a->rightleft -= 10;
	if (keycode == 124)
		a->rightleft += 10;
	if (keycode == 69)
		a->k += 5;
	if (keycode == 78)
		a->k -= 5;
	if (keycode == 88)
		a->l += 0.025;
	if (keycode == 92)
		a->l -= 0.025;
	mlx_destroy_image(a->mlx, a->image);
	mlx_put_image_to_window(a->mlx, a->win, a->image, 0, 0);
	ft_draw(a);
	return (0);
}
