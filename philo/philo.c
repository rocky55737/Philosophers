/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/15 23:42:45 by rocky            ###   ########.fr       */
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
	while (a_philo_alive(monitor) && a_coupon_valid(monitor))
	{
		spend_time(1);
	}
}

void	philo_life(t_philo *philo)
{
	size_t	time;

	while (coupon_valid(*philo) && philo_alive(*philo))
	{
		//eat
		philo = eat(philo);

		//sleep
		//print
		if (philo_is_dead(philo))
		{
			pthread_mutex_lock(philo->mutex->check_alive);
			print(philo, "is died");
			philo->live_f = DEAD;
			pthread_mutex_unlock(philo->mutex->check_alive);
			return ;
		}
		print(philo, "is sleeping");
		spend_time(philo->time_table->time_sl);

		//think
		if (philo_is_dead(philo))
		{
			pthread_mutex_lock(philo->mutex->check_alive);
			print(philo, "is died");
			philo->live_f = DEAD;
			pthread_mutex_unlock(philo->mutex->check_alive);
			return ;
		}
		//print
		print(philo, "is thinking");
		// spend_time(philo->time_table->time_th / 2);
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
