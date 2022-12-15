/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_coupon_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:11 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 17:17:38 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_coupon_valid(t_monitor *monitor)
{
	int	cnt;
	int	valid_sign;

	cnt = 0;
	valid_sign = 0;
	pthread_mutex_lock(monitor->mutex->check_coupon);
	while (cnt < monitor->philo_num)
	{
		valid_sign -= monitor->philos[cnt].coupon_f;
		cnt++;
	}
	pthread_mutex_unlock(monitor->mutex->check_coupon);
	return (valid_sign);
}
