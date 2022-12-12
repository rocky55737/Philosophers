/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:55:10 by rhong             #+#    #+#             */
/*   Updated: 2022/12/12 21:07:37 by rhong            ###   ########.fr       */
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

# define GAME_OVER	1
# define ON_GAME	0

typedef struct s_philo
{
	pthread_t	*id;
	int			*name;
	int			left_hand;
	int			right_hand;
	int			eat_count;
}	t_philo;

typedef struct s_monitor
{
	int				philo_num;
	size_t			time_d;
	size_t			time_e;
	size_t			time_sl;
	size_t			time_th;
	int				eat_limit;
	size_t			time_st;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	game_over;
}	t_monitor;

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

#endif
