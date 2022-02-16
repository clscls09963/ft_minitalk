/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverutile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:10:41 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:18:27 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverutile.h"

void		writenbr(int n, int fd)
{
	size_t	i;
	char	nbr[11];

	i = 11;
	while (i-- >= 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		if (n == 0)
		{
			while (i <= 10)
			{
				write(fd, &nbr[i], 1);
				i++;
			}
			break ;
		}
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	writenbr(n, fd);
}
