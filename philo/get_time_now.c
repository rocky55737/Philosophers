/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:00:14 by rhong             #+#    #+#             */
/*   Updated: 2022/12/14 17:13:08 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time_now(void);

size_t	get_time_now(void)
{
	struct timeval	time_now;

	gettimeofday(&time_now, 0);
	return (time_now.tv_sec * 1000 * 100 + time_now.tv_usec);
}
