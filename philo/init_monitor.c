/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:42 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 14:59:19 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor				*init_monitor(char **av);
static t_coupon			*init_coupon(char **av);
static t_time_table		*init_time_table(char **av);
static t_philo			*init_philos(t_monitor	*monitor);
static pthread_mutex_t	*init_forks(int philo_num);

t_monitor	*init_monitor(char **av)
{
	t_monitor		*monitor;

	monitor = (t_monitor *)ft_calloc(1, sizeof(t_monitor));
	monitor->philo_num = ft_atoi(av[1]);
	monitor->o_coupon = init_coupon(av);
	monitor->o_time_table = init_time_table(av);
	monitor->philos = init_philos(monitor);
	monitor->forks = init_forks(monitor->philo_num);
	pthread_mutex_init(&(monitor->check_alive), 0);
	pthread_mutex_init(&(monitor->check_coupon), 0);
	return (monitor);
}

static t_coupon	*init_coupon(char **av)
{
	t_coupon	*i_coupon;

	i_coupon = (t_coupon *)ft_calloc(1, sizeof(t_coupon));
	i_coupon->cnt = 0;
	if (av[6])
		i_coupon->limit = ft_atoi(av[5]);
	else
		i_coupon->limit = -1;
	return (i_coupon);
}

static t_time_table	*init_time_table(char **av)
{
	t_time_table	*i_time_table;

	i_time_table = (t_time_table *)ft_calloc(1, sizeof(t_time_table));
	i_time_table->time_d = (size_t)ft_atoi(av[2]);
	i_time_table->time_e = (size_t)ft_atoi(av[3]);
	i_time_table->time_sl = (size_t)ft_atoi(av[4]);
	i_time_table->time_th = i_time_table->time_d - i_time_table->time_e - i_time_table->time_sl;
	i_time_table->time_st = get_start_time();
	return (i_time_table);
}

static t_philo	*init_philos(t_monitor	*monitor)
{
	t_philo	*philos;
	int		cnt;

	philos = (t_philo *)ft_calloc(monitor->philo_num, sizeof(t_philo));
	cnt = 0;
	while (cnt < monitor->philo_num)
	{
		philos[cnt].name = cnt + 1;
		philos[cnt].left_hand = 0;
		philos[cnt].right_hand = 0;
		philos[cnt].coupon = dup_coupon(monitor->o_coupon);
		philos[cnt].time_table = dup_time_table(monitor->o_time_table);
		philos[cnt].live_f = LIVE;
		philos[cnt].coupon_f = VALID;
		cnt++;
	}
	return (philos);
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
