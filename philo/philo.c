/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/15 15:46:04 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int ac, char **av);
void	philo_game(t_monitor *monitor);
void	philo_life(t_philo *philo);
int		coupon_valid(t_philo philo);
int		philo_alive(t_philo philo);

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
			pthread_create(&(monitor->philos[cnt].id), 0, (void *)philo_life, &(monitor->philos[cnt]));
		cnt++;
	}
	spend_time(monitor->o_time_table->time_e);
	while (cnt > -1)
	{
		if (cnt % 2)
			pthread_create(&(monitor->philos[cnt].id), 0, (void *)philo_life, &(monitor->philos[cnt]));
		cnt--;
	}
	while (a_coupon_valid(monitor) && a_philo_alive(monitor))
	{
		//spend_time(monitor->o_time_table->time_d);
	}
}

void	philo_life(t_philo *philo)
{
	size_t	time;
	size_t	now_time;

	while (coupon_valid(*philo) && philo_alive(*philo))
	{
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo->mutex->check_alive);
		if (philo->time_table->time_last_e && \
		now_time - philo->time_table->time_last_e > philo->time_table->time_d)
		{
			printf("[%ldms] %d philo dead\n", get_time_now() - philo->time_table->time_st, philo->name);
			philo->live_f = DEAD;
			pthread_mutex_unlock(philo->mutex->check_alive);
			return ;
		}
		pthread_mutex_unlock(philo->mutex->check_alive);
		philo->time_table->time_last_e = now_time;
		//coupon check
		pthread_mutex_lock(philo->mutex->check_coupon);
		philo->coupon->cnt++;
		if (philo->coupon->cnt == philo->coupon->limit)
		{
			printf("[%ldms] %d philo coupon expired\n", get_time_now() - philo->time_table->time_st, philo->name);
			philo->coupon_f = EXPIRED;
			pthread_mutex_unlock(philo->mutex->check_coupon);
			return ;
		}
		pthread_mutex_unlock(philo->mutex->check_coupon);
		//pick fork
		pthread_mutex_lock(&(philo->mutex->forks[philo->name - 1]));
		pthread_mutex_lock(&(philo->mutex->forks[philo->name % philo->philo_num]));
		//print
		time = now_time - philo->time_table->time_st;
		printf("[%ldms] %d philo eat\n", time, philo->name);
		spend_time(philo->time_table->time_e);
		pthread_mutex_unlock(&(philo->mutex->forks[philo->name - 1]));
		pthread_mutex_unlock(&(philo->mutex->forks[philo->name % philo->philo_num]));

		//sleep
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo->mutex->check_alive);
		if (philo->time_table->time_last_e && \
		now_time - philo->time_table->time_last_e > philo->time_table->time_d)
		{
			printf("[%ldms] %d philo dead\n", get_time_now() - philo->time_table->time_st, philo->name);
			philo->live_f = DEAD;
			pthread_mutex_unlock(philo->mutex->check_alive);
			return ;
		}
		pthread_mutex_unlock(philo->mutex->check_alive);
		//print
		time = now_time - philo->time_table->time_st;
		printf("[%ldms] %d philo sleep\n", time, philo->name);
		spend_time(philo->time_table->time_sl / 10 * 9);

		//think
		now_time = get_time_now();
		//dead check
		pthread_mutex_lock(philo->mutex->check_alive);
		if (philo->time_table->time_last_e && \
		now_time - philo->time_table->time_last_e > philo->time_table->time_d)
		{
			printf("[%ldms] %d philo dead\n", get_time_now() - philo->time_table->time_st, philo->name);
			philo->live_f = DEAD;
			pthread_mutex_unlock(philo->mutex->check_alive);
			return ;
		}
		pthread_mutex_unlock(philo->mutex->check_alive);
		//print
		time = now_time - philo->time_table->time_st;
		printf("[%ldms] %d philo think\n", time, philo->name);
		//spend_time(philo->time_table->time_th / 10);
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
