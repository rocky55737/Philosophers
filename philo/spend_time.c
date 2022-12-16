/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:39 by rocky             #+#    #+#             */
/*   Updated: 2022/12/16 18:14:13 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(size_t time)
{
	size_t	be_time;

	if (time < 10)
		return ;
	be_time = get_time_now() + time;
	usleep (time / 2);
	while (get_time_now() < be_time)
		usleep(40);
}

void	spend_time2(size_t now_time, size_t time)
{
	size_t	be_time;

	if (time < 10)
		return ;
	be_time = now_time + time;
	usleep (time / 2);
	while (get_time_now() < be_time)
		usleep(40);
}
