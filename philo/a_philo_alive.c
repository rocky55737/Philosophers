/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_philo_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:46:17 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 13:45:19 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_philo_alive(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	pthread_mutex_lock(monitor->mutex->check_alive);
	while (cnt < monitor->philo_num)
	{
		if (monitor->philos[cnt].live_f == 0)
		{
			pthread_mutex_unlock(monitor->mutex->check_alive);
			return (0);
		}
		cnt++;
	}
	pthread_mutex_unlock(monitor->mutex->check_alive);
	return (1);
}
