/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:42:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 23:45:05 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char **av);
void	monitoring(t_monitor *monitor);

void	philo(char **av)
{
	t_monitor	*monitor;

	monitor = init_monitor(av);
	if (monitor->o_info->philo_num == 1)
	{
		print(&(monitor->philos[0]), "is dead");
		return ;
	}
	monitor = philo_game(monitor);
	monitoring(monitor);
	philo_destroy(monitor);
}

void	monitoring(t_monitor *monitor)
{
	int	cnt;

	while (e_philo_alive(monitor))
	{
		if (a_eat_enough(monitor))
		{
			cnt = 0;
			while (cnt < monitor->o_info->philo_num)
			{
				pthread_join(monitor->philos[cnt].id, 0);
				cnt++;
			}
			return ;
		}
	}
	cnt = 0;
	pthread_mutex_lock(monitor->mutex->m_dead);
	while (cnt < monitor->o_info->philo_num)
	{
		if (monitor->philos->f_dead)
			print(&(monitor->philos[cnt]), "is died");
		pthread_detach(monitor->philos[cnt].id);
		cnt++;
	}
	pthread_mutex_unlock(monitor->mutex->m_dead);
}
