/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_philo_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:46:17 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 16:27:35 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	e_philo_alive(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->o_info->philo_num)
	{
		if (philo_is_dead(&(monitor->philos[cnt])))
			return (0);
		cnt++;
	}
	return (1);
}
