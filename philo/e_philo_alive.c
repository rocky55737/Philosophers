/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_philo_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:46:17 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 23:46:42 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	e_philo_alive(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	pthread_mutex_lock(monitor->mutex->m_dead);
	while (cnt < monitor->o_info->philo_num)
	{
		if (monitor->philos[cnt].f_dead)
		{
			pthread_mutex_unlock(monitor->mutex->m_dead);
			return (0);
		}
		cnt++;
	}
	pthread_mutex_unlock(monitor->mutex->m_dead);
	return (1);
}
