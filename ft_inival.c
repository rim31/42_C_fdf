/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inival.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:47:50 by oseng             #+#    #+#             */
/*   Updated: 2016/02/12 16:02:31 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_env	ft_initvalue(void)
{
	t_env		e;

	e.xxi = 0;
	e.yyi = 0;
	e.xxf = 0;
	e.yyf = 0;
	e.updown = 0;
	e.rightleft = 0;
	e.zdeg = 0.10;
	e.xdeg = 1;
	e.ii = 0;
	e.jj = 0;
	e.kk = 0;
	e.ll = 0;
	e.xi = 0;
	e.xf = 0;
	e.yi = 0;
	e.yf = 0;
	return (e);
}

t_env			ft_inival(void)
{
	t_env		e;

	e.mlx = NULL;
	e.win = NULL;
	e.grid = 0;
	e.tab = NULL;
	e.x = 0;
	e.y = 0;
	e.i = 0;
	e.j = 0;
	e.k = 30;
	e.l = 0.05;
	e.m = 0;
	e.a = 0;
	e.ydeg = 0.15;
	ft_initvalue();
	return (e);
}
