/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:14:19 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 17:39:52 by rhong            ###   ########.fr       */
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
	int	eat_cnt;

	pthread_mutex_lock(philo->mutex->m_eat);
	eat_cnt = philo->info->eat_cnt;
	pthread_mutex_unlock(philo->mutex->m_eat);
	if (philo->info->eat_limit == -1)
		return (0);
	if (eat_cnt != philo->info->eat_limit)
		return (0);
	return (1);
}

int	philo_is_dead(t_philo *philo)
{
	size_t	now_time;

	now_time = get_time_now();
	pthread_mutex_lock(philo->mutex->m_dead);
	if (philo->info->time_last_e && \
	now_time - philo->info->time_last_e > philo->info->time_d)
	{
		pthread_mutex_unlock(philo->mutex->m_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex->m_dead);
	return (0);
}
