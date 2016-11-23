/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:03:12 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/23 17:30:58 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define BUFFER 550

typedef struct	s_tetri
{
	char	tab[3][5];
	int		isvalid;
}				t_tetri;

int		ft_get_file(char *buf, char *av);
int		ft_check_file(char *buf);
t_tetri	*ft_fill_lst(char *buf);
int		ft_resolve(t_tetri *lst);

#endif
