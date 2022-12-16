/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:37:04 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 18:57:59 by rhong            ###   ########.fr       */
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

typedef struct s_info
{
	int		philo_num;
	size_t	time_d;
	size_t	time_e;
	size_t	time_sl;
	size_t	time_th;
	size_t	time_st;
	size_t	time_last_e;
	int		eat_cnt;
	int		eat_limit;
}	t_info;

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*m_dead;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_print;
}	t_mutex;

typedef struct s_philo
{
	pthread_t	id;
	int			name;
	t_info		*info;
	t_mutex		*mutex;
	int			f_dead;
	int			f_eat;
}	t_philo;

typedef struct s_monitor
{
	t_info			*o_info;
	t_mutex			*mutex;
	t_philo			*philos;
}	t_monitor;

void		philo(char **av);
t_monitor	*init_monitor(char **av);
t_monitor	*philo_game(t_monitor *monitor);
void		monitoring(t_monitor *monitor);
void		philo_destroy(t_monitor *monitor);
void		philo_life(t_philo *philo);
t_philo		*eat(t_philo *philo);

int			ph_input_err_handler(int ac, char **av);
int			philo_eat_enough(t_philo *philo);
int			philo_is_dead(t_philo *philo);
int			e_philo_alive(t_monitor *monitor);
int			a_eat_enough(t_monitor *monitor);

t_info		*dup_info(t_info *info);
size_t		get_time_now(void);
void		spend_time(size_t time);
void		spend_time2(size_t now_time, size_t time);
void		print(t_philo *philo, char *str);

int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			str_is_integer(char *str);

#endif