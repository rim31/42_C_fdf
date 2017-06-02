/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linehoriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:49:23 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 09:52:33 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**transfomation of the table of value into a x,y,z to 2D X,Y
**center in the middle of the screen without rotation
**coefficients for better display, Xi = k.(i - longueur/2) + X0 + decalage
*/

void	ft_linehoriz(t_env a)
{
	a.ii = a.i;
	a.jj = a.j;
	a.kk = a.i - 1;
	a.ll = a.j;
	a.xi = a.k * (a.ii - a.x / 2 - a.jj) + (2000 - a.x) / 2 + a.rightleft;
	a.yi = a.k * (a.jj - a.l * ft_atoi(a.tab[a.jj][a.ii]) - a.y / 2)
		+ (1000 - a.y) / 2 + a.updown;
	a.xf = a.k * (a.kk - a.x / 2 - a.ll) + (2000 - a.x) / 2 + a.rightleft;
	a.yf = a.k * (a.ll - a.l * ft_atoi(a.tab[a.ll][a.kk]) - a.y / 2)
		+ (1000 - a.y) / 2 + a.updown;
	ft_mlx_line(&a);
}
