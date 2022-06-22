/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:35:31 by aomman            #+#    #+#             */
/*   Updated: 2022/05/30 16:35:33 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_usleep(int f_time)
{
	long	o_time;

	o_time = ft_gettime(0);
	usleep((f_time * 80) / 100);
	f_time = f_time / 1000;
	while (ft_gettime(o_time) < f_time)
		usleep(100);
}

int	validate_arguments(t_var *var)
{
	if (var->t_t_die <= 0)
	{
		printf("Error : time to die should be more than 0\n");
		return (1);
	}
	if (var->t_t_eat <= 0)
	{
		printf("Error : Time to eat should be more than 0\n");
		return (1);
	}
	if (var->t_t_sleep <= 0)
	{
		printf("Error : Time to sleep should be more than 0\n");
		return (1);
	}
	return (0);
}

int	ft_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_numbers(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (ft_valid(argv[i]) == 1)
		{
			printf("Error\n");
			return (1);
		}
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	*var;
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		var = malloc(sizeof(t_var));
		if (init_args(var, argc, argv) == -1)
			return (0);
		if (check_numbers(argc, argv) == 1)
			return (1);
		if (validate_arguments(var) == 1)
			return (1);
		data = malloc(sizeof(t_data));
		init_data(var, data);
		forks_philos(var, data);
		philo_death(data);
		return (0);
	}
	else
		printf("Error : Please give a valid arguments\n");
	return (1);
}
