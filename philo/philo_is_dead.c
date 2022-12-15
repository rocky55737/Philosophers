/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:24:59 by rhong             #+#    #+#             */
/*   Updated: 2022/12/15 17:34:21 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo)
{
	size_t	now_time;

	now_time = get_time_now();
	if (philo->time_table->time_last_e && \
	now_time - philo->time_table->time_last_e > philo->time_table->time_d)
		return (1);
	return (0);
}
