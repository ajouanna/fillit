/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:08:57 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 13:12:09 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
** lit le contenu du fichier puis en verifie la validite
*/

int		ft_get_file(char *buf, char *av)
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
	buf[ret] = 0;
	if (close(fd) == -1)
	{
		ft_putstr("Error close()\n");
		return (1);
	}
	return (ft_check_file(buf));
}
