/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:22:20 by msrun             #+#    #+#             */
/*   Updated: 2016/11/14 17:48:47 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] || s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
