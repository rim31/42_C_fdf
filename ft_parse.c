/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:02:48 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:09:16 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ontaining a int **grid with the map
** x and y are width and length max necessary for malloc a ***char str
** necessaey to get rid of space before drawing
*/

t_env		ft_parse(char **str)
{
	int		fd;
	char	*line;
	int		ret;
	t_env	e;

	e = ft_inival();
	fd = 0;
	if ((fd = open(*str, O_RDONLY)) == -1)
		exit(0);
	while ((ret = get_next_line(fd, &line)) > 0)
		e.y++;
	e.str = (char**)malloc(sizeof(char*) * e.y);
	if ((fd = open(*str, O_RDONLY)) == -1)
		exit(0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		e.str[e.i] = *(char**)malloc(sizeof(char*) * ft_strlen(line));
		e.str[e.i] = ft_strdup(line);
		e.x = ft_strnb(line, ' ');
		e.i++;
	}
	close(fd);
	e = ft_xyz(e);
	ft_mapping(e);
	return (e);
}
