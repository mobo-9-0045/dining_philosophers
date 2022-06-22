/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:45:48 by aomman            #+#    #+#             */
/*   Updated: 2022/06/04 23:45:50 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	init_data(t_var *var, t_data *data)
{
	int	i;

	i = 0;
	while (i < var->num_philo)
	{
		data[i].var = var;
		data[i].i = i;
		data[i].s_eat = 0;
		data[i].is_eat = 0;
		data[i].times_eats = 0;
		i++;
	}
}

long	ft_gettime(long begin)
{
	struct timeval	ms;
	long			tmp;

	gettimeofday(&ms, NULL);
	tmp = ms.tv_sec * 1000 + ms.tv_usec / 1000;
	return (tmp - begin);
}

int	ft_atoi(char *str)
{
	int	n;
	int	i;
	int	sing;

	n = 0;
	i = 0;
	sing = 1;
	while (str[i] <= 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (sing % 2 == 0)
		sing = -1;
	else
		sing = 1;
	return (sing * n);
}

int	init_args(t_var *var, int argc, char **argv)
{
	var->num_philo = ft_atoi(argv[1]);
	var->t_t_die = ft_atoi(argv[2]);
	var->t_t_eat = ft_atoi (argv[3]);
	var->t_t_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		var->number_eats = -1;
	if (argc == 6)
		var->number_eats = ft_atoi(argv[5]);
	var->start_t = ft_gettime(0);
	var->mutex = malloc(sizeof(pthread_mutex_t) * var->num_philo);
	var->th = malloc(sizeof(pthread_t) * var->num_philo);
	return (0);
}
