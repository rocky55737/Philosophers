/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:55:10 by rhong             #+#    #+#             */
/*   Updated: 2022/12/15 14:37:59 by rhong            ###   ########.fr       */
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

# define LIVE	1
# define DEAD	0
# define VALID	1
# define EXPIRED	0

typedef struct s_coupon
{
	int	limit;
	int	cnt;
}	t_coupon;

typedef struct s_time_table
{
	size_t	time_d;
	size_t	time_e;
	size_t	time_sl;
	size_t	time_th;
	size_t	time_st;
	size_t	time_last_e;
}	t_time_table;

typedef	struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*check_alive;
	pthread_mutex_t	*check_coupon;
}	t_mutex;


typedef struct s_philo
{
	pthread_t		id;
	int				philo_num;
	int				name;
	int				left_hand;
	int				right_hand;
	t_coupon		*coupon;
	t_time_table	*time_table;
	t_mutex			*mutex;
	int				live_f;
	int				coupon_f;
}	t_philo;

typedef struct s_monitor
{
	int				philo_num;
	t_coupon		*o_coupon;
	t_time_table	*o_time_table;
	t_philo			*philos;
	t_mutex			*mutex;
}	t_monitor;

void			philo(int ac, char **av);
size_t			get_time_now(void);
t_monitor		*init_monitor(char **av);
t_mutex			*init_mutex(int philo_num);
t_coupon		*dup_coupon(t_coupon *coupon);
t_time_table	*dup_time_table(t_time_table *time_table);
int				a_coupon_valid(t_monitor *monitor);
int				a_philo_alive(t_monitor *monitor);
void			philo_destroy(t_monitor *monitor);

void			spend_time(size_t time);


void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);

#endif
