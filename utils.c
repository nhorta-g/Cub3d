/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:37:36 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/25 13:19:47 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	skip_spaces(char *str, int i)
{
	while (str[i] && ft_isspace(i))
		i++;
	return (i);
}

int	print_error(char *str)
{
	printf("Error\n> %s\n", str);
	return (1);
}

int	free_double(char ***array)
{
	int	i;

	if (!(*array))
		return (1);
	i = -1;
	while ((*array)[++i])
	{
		if ((*array)[i])
			free((*array)[i]);
	}
	free(*array);
	*array = 0;
	return (1);
}

int	free_data(t_data *data)
{
	free_double(&data->map);
	return (1);
}

int	free_all_data(t_data *data)
{
	if (!data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	//mlx_destroy_image das texturas a acrescentar
	free_data(data);
	return (1);
}
