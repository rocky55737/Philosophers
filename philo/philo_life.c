/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:14:19 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 23:05:05 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo);
int		philo_eat_enough(t_philo *philo);
int		philo_is_dead(t_philo *philo);

void	philo_life(t_philo *philo)
{
	size_t	time;

	while (!philo_is_dead(philo))
	{
		if (philo_is_dead(philo))
			return ;
		philo = eat(philo);
		if (philo_eat_enough(philo))
			return ;
		if (philo_is_dead(philo))
			return ;
		print(philo, "is sleeping");
		spend_time(philo->info->time_sl);
		if (philo_is_dead(philo))
			return ;
		print(philo, "is thinking");
		spend_time(philo->info->time_th);
	}
}

int	philo_eat_enough(t_philo *philo)
{
	
	if (philo->info->eat_limit == -1)
		return (0);
	if (philo->info->eat_cnt != philo->info->eat_limit)
		return (0);
	pthread_mutex_lock(philo->mutex->m_eat);
	philo->f_eat = 1;
	pthread_mutex_unlock(philo->mutex->m_eat);
	return (1);
}

int	philo_is_dead(t_philo *philo)
{
	size_t	now_time;

	if (!philo->info->time_last_e)
		return (0);
	now_time = get_time_now();
	if (now_time - philo->info->time_last_e <= philo->info->time_d);
		return (0);
	pthread_mutex_lock(philo->mutex->m_dead);
	philo->f_dead = 1;
	pthread_mutex_unlock(philo->mutex->m_dead);
	return (1);
}
