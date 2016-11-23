/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:17:12 by msrun             #+#    #+#             */
/*   Updated: 2016/11/09 12:16:51 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*addmalloc;
	char	*charmem;
	size_t	i;

	i = 0;
	addmalloc = malloc(size);
	charmem = addmalloc;
	if (addmalloc)
	{
		while (i < size)
		{
			charmem[i] = 0;
			i++;
		}
		return (addmalloc);
	}
	return (0);
}
