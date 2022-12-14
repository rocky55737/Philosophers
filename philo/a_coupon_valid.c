/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_coupon_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:11 by rocky             #+#    #+#             */
/*   Updated: 2022/12/14 18:11:47 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	a_coupon_valid(t_monitor *monitor)
{
	int	cnt;
	int valid_sign;

	cnt = 0;
	valid_sign = monitor->philo_num;
	pthread_mutex_lock(&(monitor->mutex->check_coupon));
	while (cnt < monitor->philo_num)
	{
		valid_sign -= monitor->philos[cnt].coupon_f;
		cnt++;
	}
	pthread_mutex_unlock(&(monitor->mutex->check_coupon));
	return (valid_sign);
}
