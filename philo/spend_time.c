/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:39 by rocky             #+#    #+#             */
/*   Updated: 2022/12/15 15:39:35 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(size_t time)
{
	size_t	be_time;

	if (time < 1)
		return ;
	be_time = get_time_now() + (time / 10 * 9);
	usleep(time / 100);
	while (get_time_now() < be_time)
		usleep(time / 100);
}
