/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_input_err_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:15 by rhong             #+#    #+#             */
/*   Updated: 2022/12/16 17:06:20 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ph_input_err_handler(int ac, char **av);
static int	str_is_positive_number(char *str);
static int	ft_isdigit(int c);

int	ph_input_err_handler(int ac, char **av)
{
	int	cnt;

	if (ac < 5 || ac > 6)
		return (1);
	cnt = 1;
	while (cnt < ac)
	{
		if (!str_is_positive_number(av[cnt]) || !str_is_integer(av[cnt]))
			return (1);
		cnt++;
	}
	return (0);
}

static int	str_is_positive_number(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
