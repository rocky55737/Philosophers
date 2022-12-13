/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:02:38 by rhong             #+#    #+#             */
/*   Updated: 2022/12/13 13:03:01 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time_table	*init_time_table(char **av)
{
	t_time_table	*i_time_table;

	i_time_table = (t_time_table *)ft_calloc(1, sizeof(t_time_table));
	i_time_table->time_d = (size_t)ft_atoi(av[2]);
	i_time_table->time_e = (size_t)ft_atoi(av[3]);
	i_time_table->time_sl = (size_t)ft_atoi(av[4]);
	i_time_table->time_th = i_time_table->time_d - i_time_table->time_e - i_time_table->time_sl;
	i_time_table->time_st = get_start_time();
	return (i_time_table);
}
