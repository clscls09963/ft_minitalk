/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:19:29 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:20:33 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	clean(void)
{
	t_node	*ptr;

	ptr = getinstance();
	ptr->cnt = 0;
	ptr->pid.num = 0;
	ptr->len.num = 0;
	ptr->step = 0;
	if (ptr->str)
		free(ptr->str);
}
