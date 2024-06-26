/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeroual <szeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:44:35 by szeroual          #+#    #+#             */
/*   Updated: 2024/05/23 08:26:26 by szeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

double	cal(int i, double nb, char *str)
{
	double	expe;

	expe = 10;
	while (str[i] && str[i] != '.')
		nb = nb * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		nb = nb + (double)(str[i++] - '0') / (double)(expe);
		expe *= 10;
	}
	return (nb);
}

double	ft_atof(char *str)
{
	double	nb;
	int		i;
	double	sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nb = cal(i, nb, str);
	return (sign * nb);
}
