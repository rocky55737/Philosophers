/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/14 23:17:22 by rocky            ###   ########.fr       */
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
	size_t	time;
	size_t	now_time;
	while (coupon_valid(philo) && philo_alive(philo))
	{
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo.mutex->check_alive);
		if (philo.time_table->time_last_e && \
		now_time - philo.time_table->time_last_e > philo.time_table->time_d)
			philo.live_f = DEAD; // and return
		pthread_mutex_unlock(philo.mutex->check_alive);
		philo.time_table->time_last_e = now_time;
		//coupon check
		pthread_mutex_lock(philo.mutex->check_coupon);
		philo.coupon->cnt++;
		if (philo.coupon->cnt == philo.coupon->limit)
			philo.coupon_f = EXPIRED;
		pthread_mutex_unlock(philo.mutex->check_coupon);
		//pick fork
		pthread_mutex_lock(&(philo.mutex->forks[philo.name - 1]));
		pthread_mutex_lock(&(philo.mutex->forks[philo.name % philo.philo_num]));
		//print		
		time = now_time - philo.time_table->time_st;
		spend_time(philo.time_table->time_e);
		pthread_mutex_unlock(&(philo.mutex->forks[philo.name - 1]));
		pthread_mutex_unlock(&(philo.mutex->forks[philo.name % philo.philo_num]));

		//sleep
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo.mutex->check_alive);
		if (philo.time_table->time_last_e && \
		now_time - philo.time_table->time_last_e > philo.time_table->time_d)
			philo.live_f = DEAD; // and return
		pthread_mutex_unlock(philo.mutex->check_alive);
		//print
		spend_time(philo.time_table->time_sl);

		//think
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo.mutex->check_alive);
		if (philo.time_table->time_last_e && \
		now_time - philo.time_table->time_last_e > philo.time_table->time_d)
			philo.live_f = DEAD; // and return
		pthread_mutex_unlock(philo.mutex->check_alive);
		//print
		spend_time(philo.time_table->time_th);
	}
}

int	coupon_valid(t_philo philo)
{
	pthread_mutex_lock(philo.mutex->check_coupon);
	if (philo.coupon_f == VALID)
	{
		pthread_mutex_unlock(philo.mutex->check_coupon);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo.mutex->check_coupon);
		return (0);
	}
}

int	philo_alive(t_philo philo)
{
	pthread_mutex_lock(philo.mutex->check_alive);
	if (philo.live_f == LIVE)
	{
		pthread_mutex_unlock(philo.mutex->check_alive);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo.mutex->check_alive);
		return (0);
	}
}
