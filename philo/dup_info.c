/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:00:18 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 16:39:40 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*dup_info(t_info *info)
{
	t_info	*dupped;

	dupped = (t_info *)ft_calloc(1, sizeof(t_info));
	dupped->philo_num = info->philo_num;
	dupped->time_d = info->time_d;
	dupped->time_e = info->time_e;
	dupped->time_sl = info->time_sl;
	dupped->time_st = info->time_st;
	dupped->time_th = info->time_th;
	dupped->time_last_e = info->time_last_e;
	dupped->eat_cnt = info->eat_cnt;
	dupped->eat_limit = info->eat_limit;
	return (dupped);
}
