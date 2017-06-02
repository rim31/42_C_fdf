/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineverti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:53:07 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 09:54:46 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_linevert(t_env a)
{
	a.ii = a.i;
	a.jj = a.j;
	a.kk = a.i;
	a.ll = a.j - 1;
	a.xi = a.k * (a.ii - a.x / 2 - a.jj) + (2000 - a.x) / 2 + a.rightleft;
	a.yi = a.k * (a.jj - a.l * ft_atoi(a.tab[a.jj][a.ii]) - a.y / 2)
		+ (1000 - a.y) / 2 + a.updown;
	a.xf = a.k * (a.kk - a.x / 2 - a.ll) + (2000 - a.x) / 2 + a.rightleft;
	a.yf = a.k * ((a.ll) - a.l * ft_atoi(a.tab[a.ll][a.kk]) - a.y / 2)
		+ (1000 - a.y) / 2 + a.updown;
	ft_mlx_line(&a);
}
