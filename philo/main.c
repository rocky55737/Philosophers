/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rocky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:10 by rhong             #+#    #+#             */
/*   Updated: 2022/12/17 01:25:05 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void leaks(void)
{
	system("leaks philo\n");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	if (ph_input_err_handler(ac, av))
	{
		write(2, "input err\n", 10);
		return (1);
	}
	philo(av);
	return (0);
}
