/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:05:22 by msrun             #+#    #+#             */
/*   Updated: 2016/11/12 19:06:53 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		neg = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	if (str[i] > 47 && str[i] < 58)
		while (str[i] > 47 && str[i] < 58)
		{
			nb = nb * 10;
			nb = nb + (str[i] - 48);
			i++;
		}
	if (neg == 1)
		return (-nb);
	return (nb);
}
