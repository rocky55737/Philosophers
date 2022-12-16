/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:42 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 15:24:20 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor				*init_monitor(char **av);
static t_info			*init_info(char **av);
static t_mutex			*init_mutex(int philo_num);
static pthread_mutex_t	*init_forks(int philo_num);
static t_philo			*init_philos(t_monitor *monitor);

t_monitor	*init_monitor(char **av)
{
	t_monitor		*monitor;

	monitor = (t_monitor *)ft_calloc(1, sizeof(t_monitor));
	monitor->o_info = init_info(av);
	monitor->mutex = init_mutex(monitor->o_info->philo_num);
	monitor->philos = init_philos(monitor);
	return (monitor);
}

static t_info	*init_info(char **av)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	info->philo_num = ft_atoi(av[1]);
	info->time_d = (size_t)ft_atoi(av[2]);
	info->time_e = (size_t)ft_atoi(av[3]);
	info->time_sl = (size_t)ft_atoi(av[4]);
	if (av[5])
		info->eat_limit = ft_atoi(av[5]);
	else
		info->eat_limit = -1;
	info->time_th = info->time_d - info->time_e;
	info->time_th -= info->time_sl;
	if (info->time_th)
		info->time_th /= 2;
	info->time_last_e = 0;
	info->eat_cnt = 0;
	info->time_st = get_time_now();
	return (info);
}

static t_philo	*init_philos(t_monitor	*monitor)
{
	t_philo	*philos;
	int		philo_num;
	int		cnt;

	philo_num = monitor->o_info->philo_num;
	philos = (t_philo *)ft_calloc(philo_num, sizeof(t_philo));
	cnt = 0;
	while (cnt < philo_num)
	{
		philos[cnt].name = cnt + 1;
		philos[cnt].info = dup_info(monitor->o_info);
		philos[cnt].mutex = monitor->mutex;
		cnt++;
	}
	return (philos);
}

static t_mutex	*init_mutex(int philo_num)
{
	t_mutex			*mutex;
	pthread_mutex_t	*alive_m;
	pthread_mutex_t	*coupon_m;

	mutex = (t_mutex *)ft_calloc(1, sizeof(t_mutex));
	mutex->forks = init_forks(philo_num);
	alive_m = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->m_dead = alive_m;
	pthread_mutex_init(mutex->m_dead, 0);
	coupon_m = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->m_eat = coupon_m;
	pthread_mutex_init(mutex->m_eat, 0);
	mutex->m_print = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex->m_print, 0);
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
