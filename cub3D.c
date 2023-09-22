/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/22 10:30:15 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_window(t_data *data)
{
	data->mlx.win = mlx_new_window(data->mlx.ptr, MAP_W, MAP_H, "Cub3d");
	if (!data->mlx.win)
	{
		perror("Error creatig window");
		free_all_data(data);
		exit(1);
	}
	put_image
	mlx_loop(data->mlx.ptr);
}

int	init_data(t_data *data)
{
	data->c_ceiling = -1;
	data->c_floor = -1;
	data->gnl_x = 0;
	data->map_x = 0;
	data->x = -1;
	data->y = -1;
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
	{
		perror("Error establishing connection to graphical system");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)calloc(1, sizeof(t_data));
	if (ac != 2)
		return (write(1, "Error\n-Wrong number of args", 27));
	init_data(data);
	init_window(data);
	if (!parser(av, data))
		free_data(data);
}
