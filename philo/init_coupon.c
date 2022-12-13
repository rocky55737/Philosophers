/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coupon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:01:31 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:02:00 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_coupon	*init_coupon(char **av)
{
	t_coupon	*i_coupon;

	i_coupon = (t_coupon *)ft_calloc(1, sizeof(t_coupon));
	i_coupon->cnt = 0;
	if (av[6])
		i_coupon->limit = ft_atoi(av[5]);
	else
		i_coupon->limit = -1;
	return (i_coupon);
}
