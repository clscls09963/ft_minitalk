/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:15:07 by hyeykim           #+#    #+#             */
/*   Updated: 2021/06/14 19:17:46 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdlib.h>
# include "clientutile.h"

union		u_data
{
	char	arr[4];
	pid_t	pid;
};

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
#endif
