/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:39 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 17:12:39 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(size_t time)
{
	size_t	be_time;

	if (time < 1)
		return ;
	be_time = get_time_now() + time;
	usleep(time / 10 * 7);
	while (get_time_now() < be_time)
		usleep(40);
}
