/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_eat_enough.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:11 by rocky             #+#    #+#             */
/*   Updated: 2023/03/20 16:14:31 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_eat_enough(t_monitor *monitor)
{
	int	cnt;
	int	eat_f_cnt;

	eat_f_cnt = 0;
	cnt = 0;
	pthread_mutex_lock(monitor->mutex->m_eat);
	while (cnt < monitor->o_info->philo_num)
	{
		eat_f_cnt += monitor->philos[cnt].f_eat;
		cnt++;
	}
	pthread_mutex_unlock(monitor->mutex->m_eat);
	if (eat_f_cnt == monitor->o_info->philo_num)
		return (1);
	return (0);
}
