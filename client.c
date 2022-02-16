/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:01:33 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:17:51 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	prettysend(int pid, char word, char num)
{
	if (word & num)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
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

int		main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
