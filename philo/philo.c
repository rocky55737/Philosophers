/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/14 17:53:10 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int ac, char **av);
void	philo_game(t_monitor *monitor);

void	philo(int ac, char **av)
{
	t_monitor		*monitor;

	monitor = init_monitor(av);
	philo_game(monitor);
	philo_destroy(monitor);
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
	while (a_coupon_valid(monitor) && a_philo_alive(monitor))
	{
	}
}

void	philo_life(t_philo philo)
{
	while (philo.coupon_f && philo.live_f)
	{
		
	}
}

int	coupon_valid(t_philo philo)
{
	
}