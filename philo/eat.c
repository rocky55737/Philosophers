/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:46:04 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 23:50:31 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo		*eat(t_philo *philo);
static void	do_eat(t_philo *philo);
static void	pick_fork(t_philo *philo);
static void	put_fork(t_philo *philo);

t_philo	*eat(t_philo *philo)
{
	if (philo_is_dead(philo))
		return (philo);
	pthread_mutex_lock(philo->mutex->m_eat);
	philo->info->eat_cnt++;
	pthread_mutex_unlock(philo->mutex->m_eat);
	do_eat(philo);
	return (philo);
}

static void	do_eat(t_philo *philo)
{
	size_t	now_time;

	pick_fork(philo);
	print(philo, "is eating");
	now_time = get_time_now();
	philo->info->time_last_e = get_time_now();
	spend_time2(now_time, philo->info->time_e);
	put_fork(philo);
}

static void	pick_fork(t_philo *philo)
{
	if (philo->name % 2 == 0)
	{
		pthread_mutex_lock(&(philo->mutex->forks[philo->name - 1]));
		print(philo, "has taken a fork");
		if (philo->name == philo->info->philo_num)
			pthread_mutex_lock(&(philo->mutex->forks[0]));
		else
			pthread_mutex_lock(&(philo->mutex->forks[philo->name]));
		print(philo, "has taken a fork");
	}
	else
	{
		if (philo->name == philo->info->philo_num)
			pthread_mutex_lock(&(philo->mutex->forks[0]));
		else
			pthread_mutex_lock(&(philo->mutex->forks[philo->name]));
		print(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->mutex->forks[philo->name - 1]));
		print(philo, "has taken a fork");
	}
}

static void	put_fork(t_philo *philo)
{
	if (philo->name % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->mutex->forks[philo->name - 1]));
		if (philo->name == philo->info->philo_num)
			pthread_mutex_unlock(&(philo->mutex->forks[0]));
		else
			pthread_mutex_unlock(&(philo->mutex->forks[philo->name]));
	}
	else
	{
		if (philo->name == philo->info->philo_num)
			pthread_mutex_unlock(&(philo->mutex->forks[0]));
		else
			pthread_mutex_unlock(&(philo->mutex->forks[philo->name]));
		pthread_mutex_unlock(&(philo->mutex->forks[philo->name - 1]));
	}
}
