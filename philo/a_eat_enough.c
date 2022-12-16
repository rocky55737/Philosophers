/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_eat_enough.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:11 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 23:10:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_eat_enough(t_monitor *monitor)
{
	int	cnt;
	int eat_f_cnt;

	eat_f_cnt = 0;
	cnt = 0;
	while (cnt < monitor->o_info->philo_num)
	{
		pthread_mutex_lock(monitor->mutex->m_eat);
		eat_f_cnt += monitor->philos[cnt].f_eat;
		pthread_mutex_unlock(monitor->mutex->m_eat);
		cnt++;
	}
	if (eat_f_cnt == monitor->o_info->philo_num)
		return (1);
	return (0);
}
