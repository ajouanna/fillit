/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:03:12 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/24 16:43:58 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER 550

typedef struct	s_tetri
{
	char	tab[4][5];
	int		isvalid;
}				t_tetri;

typedef struct	s_map
{
	char	**map;
	int 	taille_map;
}				t_map;

int				ft_get_file(char *buf, char *av);
int				ft_check_file(char *buf);
t_tetri			*ft_fill_lst(char *buf);
int				ft_resolve(t_tetri *lst);
t_map			*alloc_map(int taille_map);
void			free_map(t_map *map);
void			cleanup_map(t_map *map);
void			display_map(t_map *map);
void			copy_map(t_map *cp_map, t_map *map);

#endif
