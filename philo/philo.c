/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/12 21:16:59 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int ac, char **av);
size_t	get_start_time(void);

void	philo(int ac, char **av)
{
	t_monitor	*monitor;

	//philo = philo_init(ac, av);
	monitor = (t_monitor *)ft_calloc(1, sizeof(t_monitor));
	monitor->philo_num = ft_atoi(av[0]);
	monitor->time_d = (size_t)ft_atoi(av[1]);
	monitor->time_e = (size_t)ft_atoi(av[2]);
	monitor->time_sl = (size_t)ft_atoi(av[3]);
	monitor->time_th = monitor->time_d - monitor->time_e - monitor->time_sl;
	if (av[4])
		monitor->eat_limit = ft_atoi(av[4]);
	else
		monitor->eat_limit = 0;
	monitor->time_st = get_start_time();
	monitor->philos = (t_philo *)ft_calloc(monitor->philo_num, sizeof(t_philo));
	monitor->forks = 

	//philo_game(philo_data);
	//philo_destroy(philo_data);
}

size_t	get_start_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, 0);
	return (start_time.tv_sec * 1000 * 100 + start_time.tv_usec);
}
