/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:00:09 by msrun             #+#    #+#             */
/*   Updated: 2016/11/27 16:25:24 by ajouanna         ###   ########.fr       */
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
	int			err;

	err = 0;
	if (ac != 2)
		ft_putstr("usage : ./fillit source_file\n");
	if (ac != 2)
		return (1);
	if (!err && ft_get_file(buf, av[1]) != 0)
		err = 1;
	if ((lst = ft_fill_lst(buf)) == 0)
		err = 1;
	if (!err && ft_check_lst(lst) == 1)
		err = 1;
	if (!err)
		ft_replace(lst);
	if (!err && ft_resolve(lst) == 0)
		err = 1;
	if (err)
		ft_putstr("error\n");
	ft_free_lst(lst);
	if (!err)
		return (1);
	return (0);
}
