/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_coupon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:03:39 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:04:21 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_coupon	*dup_coupon(t_coupon *coupon)
{
	t_coupon	*dupped;

	dupped = (t_coupon *)ft_calloc(1, sizeof(t_coupon));
	dupped->limit = coupon->limit;
	dupped->cnt = coupon->cnt;
	return (dupped);
}
