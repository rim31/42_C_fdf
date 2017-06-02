/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line.C                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:56:38 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 22:21:35 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**equation : y = ax + b, a = Dy/Dx.  if xfinal = xinitial, problem coef
**draw line according numbre of pixel Dx or Dy. Thus, vertically, apply
**just increase y by pixel, if not, increase x with the coefficient
*/

void	ft_mlx_line(t_env *e)
{
	t_env	c;

	c = ft_inival();
	ft_zrot(&e->xi, &e->yi, *e);
	ft_zrota(&e->xf, &e->yf, *e);
	c.d = (e->xi == e->xf) ? 100 * fabsf(e->yf - e->yi) :
	100 * fabsf(e->xf - e->xi);
	c.a = (e->xi == e->xf) ? 1 : (((float)e->yf - (float)e->yi) /
	((float)e->xf - (float)e->xi));
	c.xxi = e->xi;
	c.b = e->yi - c.a * e->xi;
	c.i = -1;
	e->dr.color = (e->xdeg != 0) ? rand() % 999999999 : 0xFFFFFF;
	while (c.i++ <= c.d)
	{
		if (e->xi != e->xf)
		{
			c.yyi = c.a * c.xxi + c.b;
			c.xxi = (e->xi < e->xf) ? c.xxi + 0.01 : c.xxi - 0.01;
		}
		else
			c.yyi = (e->yi < e->yf) ? 0.01 * c.i + e->yi : e->yi - 0.01 * c.i;
		mlx_pixel_put_to_image(c.xxi, c.yyi, e);
	}
}
