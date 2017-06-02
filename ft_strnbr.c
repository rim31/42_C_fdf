/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:09:35 by oseng             #+#    #+#             */
/*   Updated: 2016/02/11 10:10:38 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** just count the number of word separate by space here
*/

int			ft_strnb(char const *s, char c)
{
	size_t	a;
	size_t	i;
	size_t	nb;
	int		begin;
	int		end;

	nb = 0;
	a = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		begin = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > begin)
			nb++;
	}
	return (nb);
}
