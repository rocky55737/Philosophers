/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:55:10 by rhong             #+#    #+#             */
/*   Updated: 2022/12/12 16:11:04 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo_data
{
	int				philo_num;
	//pthread_t		*philos;
	//pthread_mutex_t	*forks;
	unsigned long	time_d;
	unsigned long	time_e;
	unsigned long	time_s;
	int				eat_limit;
}	t_philo_data;

typedef struct s_philosopher
{
	int	*name;
	int	left_hand;
	int	right_hand;
}	t_philosopher;

#endif
