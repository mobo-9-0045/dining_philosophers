/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:45:00 by aomman            #+#    #+#             */
/*   Updated: 2022/06/21 16:45:03 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	how_eat_times(t_data *data)
{
	int	i;

	i = 0;
	if (data->var->number_eats == -1)
		return (0);
	while (i < data->var->num_philo)
	{
		if (data[i].times_eats < data->var->number_eats)
			break ;
		i++;
	}
	if (i == data->var->num_philo)
		return (1);
	return (0);
}

void	*philo_death(t_data *dt)
{
	int		i;
	long	tm;

	tm = ft_gettime(dt[0].var->start_t);
	i = 0;
	while (1)
	{
		if (dt[i].is_eat == 0 && (int)(tm - dt[i].s_eat) >= dt[0].var->t_t_die)
		{
			pthread_mutex_lock(&dt->var->print);
			printf("%04ld %d died\n", ft_gettime(dt[0].var->start_t), i + 1);
			return (0);
		}
		i = (i + 1) % dt->var->num_philo;
		tm = ft_gettime(dt[0].var->start_t);
		if (how_eat_times(dt) == 1)
		{
			pthread_mutex_lock(&dt->var->print);
			return (0);
		}
		usleep(10);
	}
	return (0);
}
