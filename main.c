/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:17:36 by oseng             #+#    #+#             */
/*   Updated: 2016/02/12 14:47:24 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		a;
	t_env	e;

	a = 0;
	fd = 0;
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (0);
		e = ft_inival();
		e = ft_parse(&argv[1]);
	}
	return (0);
}