/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:55:12 by msrun             #+#    #+#             */
/*   Updated: 2016/11/23 19:19:45 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdio.h>

t_tetri		*ft_alloc(t_tetri *lst, char *buf)
{
	int n;
	int i;

	n = (ft_strlen(buf) + 1) / 21;
	i = 0;
	lst = malloc(sizeof(t_tetri) * n + 1);
	if (lst == 0)
		return (0);
	while (i < n)
	{
		lst[i].isvalid = 1;
		++i;
	}
	lst[i].isvalid = 0;
	return (lst);
}

void	ft_fill(t_tetri *lst, char *buf)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (buf[i])
	{
		lst[nb].tab[(i - nb) / 5][(i - nb) % 5] = buf[i];
		if (buf[i] == '\n')
			lst[nb].tab[(i - nb) / 5][(i - nb) % 5] = 0;
//		printf("%s     , %d  , %d\n", lst[nb].tab[(i-nb) / 5], (i - nb ) / 5, (i-nb)%5);
		++i;
		if (i % 21 == 0)
		{
//			printf("bloub\n");
//			printf("%s\n", lst[nb].tab[1]);
//			printf("%s\n", lst[nb].tab[2]);
//			printf("%s\n", lst[nb].tab[3]);
			++nb;
//			++i;
		}
	}
}

t_tetri *ft_fill_lst(char *buf)
{
	t_tetri	*lst;
	
	lst = NULL;
	lst = ft_alloc(lst, buf);
	if (lst == 0)
		return (NULL);
	ft_fill(lst, buf);
	return (lst);
}
