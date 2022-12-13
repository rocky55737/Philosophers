/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:44 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:51:55 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int ac, char **av);

void	philo(int ac, char **av)
{
	t_monitor		*monitor;

	monitor = init_monitor(av);

	//philo_game(philo_data);
	//philo_destroy(philo_data);
}

t_monitor	*init_monitor(char **av)
{
	t_monitor		*monitor;

	monitor = (t_monitor *)ft_calloc(1, sizeof(t_monitor));
	monitor->philo_num = ft_atoi(av[1]);
	monitor->o_coupon = init_coupon(av);
	monitor->o_time_table = init_time_table(av);
	monitor->philos = init_philos(monitor);
	return (monitor);
}

t_philo	*init_philos(t_monitor	*monitor)
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
