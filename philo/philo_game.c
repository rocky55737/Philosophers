/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:12:37 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 18:45:19 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor	*philo_game(t_monitor *monitor);

t_monitor	*philo_game(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->o_info->philo_num)
	{
		pthread_create(&(monitor->philos[cnt].id), 0, \
		(void *)philo_life, &(monitor->philos[cnt]));
		cnt += 2;
	}
	cnt = monitor->o_info->philo_num - 1;
	if (cnt % 2 == 0)
		cnt--;
	while (cnt > -1)
	{
		pthread_create(&(monitor->philos[cnt].id), 0, \
		(void *)philo_life, &(monitor->philos[cnt]));
		cnt -= 2;
	}
	return (monitor);
}
