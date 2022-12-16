/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:59:30 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 16:16:53 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		philo_destroy(t_monitor *monitor);
static void	free_philos(t_philo *philos, int num);

void	philo_destroy(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->o_info->philo_num)
	{
		pthread_mutex_destroy(&(monitor->mutex->forks[cnt]));
		cnt++;
	}
	pthread_mutex_destroy(monitor->mutex->m_eat);
	pthread_mutex_destroy(monitor->mutex->m_dead);
	free(monitor->o_info);
	free_philos(monitor->philos, monitor->o_info->philo_num);
	free(monitor->mutex->forks);
	free(monitor->mutex);
	free(monitor);
}

static void	free_philos(t_philo *philos, int num)
{
	int	cnt;

	cnt = 0;
	while (cnt < num)
	{
		free(philos[cnt].info);
		cnt++;
	}
	free(philos);
}
