/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:39 by rocky             #+#    #+#             */
/*   Updated: 2022/12/14 17:29:06 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(size_t time)
{
	size_t	be_time;

	be_time = get_time_now() + time;
	usleep(time / 9 * 10);
	while (get_time_now < be_time)
		usleep(time / 10);
}