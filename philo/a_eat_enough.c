/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_eat_enough.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:11 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 16:23:51 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_eat_enough(t_monitor *monitor)
{
	int	cnt;

	cnt = 0;
	while (cnt < monitor->o_info->philo_num)
	{
		if (philo_eat_enough(&(monitor->philos[cnt])))
			return (1);
		cnt++;
	}
	return (0);
}
