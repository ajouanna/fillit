/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:08:57 by msrun             #+#    #+#             */
/*   Updated: 2016/11/30 18:21:21 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
** detecte les caracteres interdits
*/

static int	check_car(char *buf, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

/*
** lit le contenu du fichier puis en verifie la validite
*/

int			ft_get_file(char *buf, char *av)
{
	int	fd;
	int	ret;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error open()\n");
		return (1);
	}
	ret = read(fd, buf, BUFFER);
	if (ret == -1)
	{
		ft_putstr("Error read()\n");
		return (1);
	}
	if (!check_car(buf, ret))
		return (1);
	buf[ret] = 0;
	if (close(fd) == -1)
	{
		ft_putstr("Error close()\n");
		return (1);
	}
	return (ft_check_file(buf));
}
