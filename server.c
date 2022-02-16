/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:56:43 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 20:49:00 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	fnsig(int num)
{
	static	char	word = 0;
	static	int		cnt = 0;

	word <<= 1;
	word += (num + 1) % 2;
	cnt++;
	if (cnt == 8)
	{
		write(1, &word, 1);
		word = 0;
		cnt = 0;
	}
	usleep(1);
}

int		main(void)
{
	signal(SIGUSR1, (void *)fnsig);
	signal(SIGUSR2, (void *)fnsig);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
