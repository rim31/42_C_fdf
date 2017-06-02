/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:32:38 by oseng             #+#    #+#             */
/*   Updated: 2015/12/11 15:40:39 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		a = i;
		b = 0;
		while (s1[a++] == s2[b++])
		{
			if (s2[b] == '\0')
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return (NULL);
}
