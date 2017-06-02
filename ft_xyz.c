/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xyz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:10:52 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:11:59 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**storing map of value in ***char table because
**value aren't usable out of the loop while
*/

t_env	ft_xyz(t_env e)
{
	char **tmp;

	tmp = NULL;
	e.i = 0;
	e.j = -1;
	if (!(e.tab = (char***)malloc(sizeof(char*) * e.y)))
		exit(0);
	while (e.j++ < e.y - 1)
	{
		tmp = ft_strsplit(e.str[e.j], ' ');
		if (!(e.tab[e.j] = (char**)malloc(sizeof(char*) * e.x)))
			exit(0);
		e.i = 0;
		while (tmp[e.i])
		{
			e.tab[e.j][e.i] = (char*)malloc(sizeof(char*) *
					ft_strlen(tmp[e.i]));
			e.tab[e.j][e.i] = ft_strdup(tmp[e.i]);
			e.i++;
		}
	}
	return (e);
}
