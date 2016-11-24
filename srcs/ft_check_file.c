/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:09:09 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 13:15:50 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
** verifie le nombre max de caracteres attendus
*/

int		ft_check_max(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && i < 550)
		i++;
	if (i >= 546)
		return (1);
	return (0);
}

/*
** verifie que chqaye tetrimino est bien un carre
*/

int		ft_check_itsquare(char *buf)
{
	int i;
	int y;
	int n;

	i = 0;
	y = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			++n;
		if (((i - y + 1) % 20 == 0 && n != 4 && i != 0) || (buf[i + 1] == 0 &&
					(i - y + 1) % 20 != 0) || ((i - y + 1) % 5 == 0 &&
						buf[i] != '\n') || (buf[i] == '\n' && buf[i - 1] == '\n'
							&& buf[i - 2] == '\n'))
			return (1);
		if (buf[i] == '\n' && buf[i - 1] == '\n')
		{
			n = 0;
			++y;
		}
		++i;
	}
	return (0);
}

/*
** verifie que le contenu du fichier charge dans le param buf est valide
*/

int		ft_check_file(char *buf)
{
	int i;
	int err;

	i = 0;
	err = 0;
	err = ft_check_max(buf);
	if (!err)
		err = ft_check_itsquare(buf);
	return (err);
}
