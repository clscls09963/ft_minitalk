/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientutile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:00:32 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:18:01 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientutile.h"

int			ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	minus = 1;
	num = 0;
	while (*str >= 9 & *str <= 13 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = ((num * 10) + (*str - '0') * minus);
		if (minus == 1 && num < 0)
			return (-1);
		else if (minus == -1 && num > 0)
			return (0);
		str++;
	}
	return (num);
}

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
