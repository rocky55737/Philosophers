/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:00:14 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:01:00 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_start_time(void);

size_t	get_start_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, 0);
	return (start_time.tv_sec * 1000 * 100 + start_time.tv_usec);
}
