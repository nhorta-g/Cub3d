/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:37:36 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/07 01:22:01 by nuno             ###   ########.fr       */
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

int	free_double(char **array)
{
	int	i;

	if (!array)
		return (1);
	i = 0;
	while (array[i])
		if ((array)[i])
			free(array[i++]);
	free(array);
	return (0);
}

int	free_data(t_data *data)
{
	if (free_double(data->map))
		printf("Warning, matrix data->map doesnt exist to be freed");
	free(data);
	return (1);
}

int	free_all_data(t_data *data)
{
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mmap.text[0])
		mlx_destroy_image(data->mlx.ptr, data->mmap.text[0]);
	if (data->mmap.text[1])
		mlx_destroy_image(data->mlx.ptr, data->mmap.text[1]);
	if (data->mmap.text[2])
		mlx_destroy_image(data->mlx.ptr, data->mmap.text[2]);
	if (data->mlx.ptr)
		mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	free_data(data);
	return (1);
}

void	perror_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	perror_exit_free_all_data(t_data *data, char *msg, int code)
{
	free_all_data(data);
	perror_exit(msg, code);
}
