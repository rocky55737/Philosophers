/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:31:27 by rhong             #+#    #+#             */
/*   Updated: 2022/12/15 14:39:35 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex					*init_mutex(int philo_num);
static pthread_mutex_t	*init_forks(int philo_num);

t_mutex	*init_mutex(int philo_num)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)ft_calloc(1, sizeof(t_mutex));
	mutex->forks = init_forks(philo_num);
	mutex->check_alive = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex->check_alive, 0);
	mutex->check_coupon	= (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex->check_coupon, 0);
	return (mutex);
}

static pthread_mutex_t	*init_forks(int philo_num)
{
	pthread_mutex_t	*forks;
	int				cnt;

	forks = (pthread_mutex_t *)ft_calloc(philo_num, sizeof(pthread_mutex_t));
	cnt = 0;
	while (cnt < philo_num)
	{
		pthread_mutex_init(&(forks[cnt]), 0);
		cnt++;
	}
	return (forks);
}