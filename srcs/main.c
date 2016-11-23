/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:00:09 by msrun             #+#    #+#             */
/*   Updated: 2016/11/23 15:12:59 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_fillit.h"

int		main(int ac, char *av[])
{
	char		buf[BUFFER + 1];

	if (ac != 2)
		ft_putstr("usage : ./fillit source_file\n");
	if (ft_get_file(buf, av[1]) != 0)
		printf("err");
	return (0);
}
