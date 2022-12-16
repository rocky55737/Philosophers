/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:33:59 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 15:09:44 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str)
{
	size_t	time;

	time = get_time_now() - philo->info->time_st;
	pthread_mutex_lock(philo->mutex->m_print);
	printf("%ldms %d %s\n", time, philo->name, str);
	pthread_mutex_unlock(philo->mutex->m_print);
}
