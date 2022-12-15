/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:46:04 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 23:07:22 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*eat(t_philo *philo)
{
	size_t	time;

	//coupon check
	if (philo->coupon->limit != -1 && philo->coupon->cnt == philo->coupon->limit)
	{
		print(philo, "coupon expired");
		pthread_mutex_lock(philo->mutex->check_coupon);
		philo->coupon_f = EXPIRED;
		pthread_mutex_unlock(philo->mutex->check_coupon);
		return (philo);
	}
	philo->coupon->cnt++;
	time = get_time_now() - philo->time_table->time_st;
	//dead check
	if (philo_is_dead(philo))
	{
		pthread_mutex_lock(philo->mutex->check_alive);
		print(philo, "is died");
		philo->live_f = DEAD;
		pthread_mutex_unlock(philo->mutex->check_alive);
		return (philo);
	}
	//pick fork
	pthread_mutex_lock(&(philo->mutex->forks[philo->name - 1]));
	print(philo, "has taken a fork");
	if (philo->name == philo->philo_num)
		pthread_mutex_lock(&(philo->mutex->forks[0]));
	else
		pthread_mutex_lock(&(philo->mutex->forks[philo->name]));
	print(philo, "has taken a fork");
	//print
	print(philo, "is eating");
	philo->time_table->time_last_e = get_time_now();
	spend_time(philo->time_table->time_e);
	pthread_mutex_unlock(&(philo->mutex->forks[philo->name - 1]));
	if (philo->name == philo->philo_num)
		pthread_mutex_unlock(&(philo->mutex->forks[0]));
	else
		pthread_mutex_unlock(&(philo->mutex->forks[philo->name]));
	return (philo);
}