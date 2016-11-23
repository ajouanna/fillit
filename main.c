/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:00:09 by msrun             #+#    #+#             */
/*   Updated: 2016/11/22 17:47:26 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

#define BUFFER 546

typedef struct	s_listtet
{
	char				mino[4][4];
	struct tetrimino	*next;
}				t_listtet;


size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

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

int		ft_check_file(char *buf)
{
	int i;
	int err;

	i = 0;
	err = 0;
	err = ft_check_max(buf);
	if (!err)
		err = ft_check_itsquare(buf);
	printf("  %d  ", err);
	return (err);
}

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

t_listtet	*ft_newtet()
{
	t_listtet *tmp;

	tmp = malloc(sizeof(t_listtet));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	return (tmp);
}

t_listtet	*ft_get_lst(int ac)
{
	t_listtet *tmp;
	t_listtet *tmp2;
	t_listtet *addr;
	int i;

	i = 0;
	tmp = ft_newtet();
	if (!tmp)
		return (0);
	addr = tmp;
	while (i < ac)
	{
		tmp2 = tmp;
		tmp = ft_newtet();
		if (!tmp)
			return (0);
		tmp2->next = tmp;
		i++;
	}
	return (addr);
}

int		ft_fill_lst(t_listtet list)
{
}

int		main(int ac, char *av[])
{
	char		buf[BUFFER + 1];
	t_listtet	*tetstart;

	if (ac != 2)
		ft_putstr("usage : ./fillit source_file\n");
	if (ft_get_file(buf, av[1]) != 0)
		printf("err");
	tetstart = ft_get_lst(ac);
	if (!tetstart)
		printf("err2");
	ft_fill_lst(buf);
	return (0);
}
