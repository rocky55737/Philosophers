/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 15:58:59 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int ac, char **av);

void	philo(int ac, char **av)
{
	t_monitor		*monitor;

	monitor = init_monitor(av);
	philo_game(monitor);
	philo_destroy(monitor);
}

void	philo_destroy(t_monitor *monitor)
{
	//detach all
	//mutex destroy
	//free all
	free(monitor->o_coupon);
	free(monitor->o_time_table);
	free_philos(monitor->philos, monitor->philo_num);
	free(monitor);
}

void	philo_game(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->philo_num)
	{
		if (!(cnt % 2))
			pthread_create(&(monitor->philos[cnt].id), 0, philo_life, &(monitor->philos[cnt]));
		cnt++;
	}
	usleep(monitor->o_time_table->time_e * 10 / 9);
	while (cnt > -1)
	{
		if (cnt % 2)
			pthread_create(&(monitor->philos[cnt].id), 0, philo_life, &(monitor->philos[cnt]));
		cnt--;
	}
	while (coupon_valid(monitor->philos) && philo_alive(monitor->philos))
	{
	}
}

void	philo_life()
{
//	whlie
//	{
//		eat;
//		sleep;
//		think;
//	}
}
