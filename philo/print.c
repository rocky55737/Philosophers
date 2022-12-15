/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:33:59 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 22:36:32 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str)
{
	size_t	time;

	time = get_time_now() - philo->time_table->time_st;
	pthread_mutex_lock(philo->mutex->print_m);
	printf("%ldms %d %s\n", time, philo->name, str);
	pthread_mutex_unlock(philo->mutex->print_m);
}