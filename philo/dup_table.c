/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:04:38 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:04:54 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time_table	*dup_time_table(t_time_table *time_table)
{
	t_time_table	*dupped;

	dupped = (t_time_table *)ft_calloc(1, sizeof(t_time_table));
	dupped->time_d = time_table->time_d;
	dupped->time_e = time_table->time_e;
	dupped->time_sl = time_table->time_sl;
	dupped->time_st = time_table->time_st;
	dupped->time_th = time_table->time_th;
	return (dupped);
}
