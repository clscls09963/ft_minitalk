/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:38:23 by dsong             #+#    #+#             */
/*   Updated: 2021/06/14 19:21:16 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <stdlib.h>
# include "serverutile.h"

union				u_data
{
	char			arr[4];
	int				num;
};

typedef struct		s_node
{
	int				cnt;
	int				step;
	union u_data	len;
	union u_data	pid;
	char			*str;
}					t_node;

void				clean(void);
t_node				*getinstance(void);
void				fnstep0(int num, struct __siginfo *ppp, void *pp);
void				fnstep1(int num, struct __siginfo *ppp, void *pp);
void				fnstep2(int num, struct __siginfo *ppp, void *pp);

#endif
