/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:12:08 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:12:47 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**rotation arround z axe
*/

void			ft_zrota(float *k, float *l, t_env e)
{
	float	v;
	float	w;

	v = *k;
	w = *l;
	*k = v * cosf(e.zdeg) - w * sinf(e.zdeg);
	*l = v * sinf(e.zdeg) + w * cosf(e.zdeg);
}

void			ft_zrot(float *i, float *j, t_env e)
{
	float	x;
	float	y;

	x = *i;
	y = *j;
	*i = x * cosf(e.zdeg) - y * sinf(e.zdeg);
	*j = x * sinf(e.zdeg) + y * cosf(e.zdeg);
}
