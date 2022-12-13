/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:59:30 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 16:09:22 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		philo_destroy(t_monitor *monitor);
static void	free_philos(t_philo *philos, int num);

void	philo_destroy(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->philo_num)
	{
		pthread_detach(monitor->philos[cnt].id);
		pthread_mutex_destroy(&(monitor->forks[cnt]));
		cnt++;
	}
	pthread_mutex_destroy(&(monitor->check_alive));
	pthread_mutex_destroy(&(monitor->check_coupon));
	free(monitor->o_coupon);
	free(monitor->o_time_table);
	free_philos(monitor->philos, monitor->philo_num);
	free(monitor->forks);
	free(monitor);
}

static void	free_philos(t_philo *philos, int num)
{
	int	cnt;

	cnt = 0;
	while (cnt < num)
	{
		free(philos[cnt].coupon);
		free(philos[cnt].time_table);
		cnt++;
	}
	free(philos);
}
