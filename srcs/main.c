/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:00:09 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 16:48:11 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdio.h>

/*
** main : enchainement des traitements et gestion des erreurs
*/

int		main(int ac, char *av[])
{
	char		buf[BUFFER + 1];
	t_tetri		*lst;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (1);
	}
	if (ft_get_file(buf, av[1]) != 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	lst = ft_fill_lst(buf);
	if (lst == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (ft_check_lst(lst) == 1)
		return (1);
	ft_replace(lst);
	if (ft_resolve(lst) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
