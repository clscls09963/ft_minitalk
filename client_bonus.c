/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:01:33 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:17:41 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int		*getinstance(void)
{
	static int	finished = 1;

	return (&finished);
}

void	prettysend(int pid, char word, char num)
{
	if (word & num)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(20);
}

void	send(int pid, char word)
{
	prettysend(pid, word, 0x80);
	prettysend(pid, word, 0x40);
	prettysend(pid, word, 0x20);
	prettysend(pid, word, 0x10);
	prettysend(pid, word, 0x08);
	prettysend(pid, word, 0x04);
	prettysend(pid, word, 0x02);
	prettysend(pid, word, 0x01);
}

void	fnsig1(void)
{
	write(1, "Send without problem\n", 21);
	*(getinstance()) = 0;
}

int		main(int argc, char **argv)
{
	union u_data	mypid;
	union u_data	len;
	pid_t			pid;
	int				i;

	signal(SIGUSR1, (void *)fnsig1);
	if (argc == 3)
	{
		mypid.pid = getpid();
		pid = ft_atoi(argv[1]);
		len.pid = ft_strlen(argv[2]);
		i = 0;
		while (i < 4)
			send(pid, mypid.arr[i++]);
		usleep(200);
		i = 0;
		while (i < 4)
			send(pid, len.arr[i++]);
		i = 0;
		while (argv[2][i])
			send(pid, argv[2][i++]);
		while (*getinstance())
			usleep(1);
	}
	return (0);
}
