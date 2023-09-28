/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/28 14:42:16 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_window(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		perror_exit_free_all_data(data, "Error establishing connection to graphical system", 1);
	data->mlx.win = mlx_new_window(data->mlx.ptr, data->map_x, data->map_y, "Cub3d");
	if (!data->mlx.win)
		perror_exit_free_all_data(data, "Error creating window", 1);
	data->img.mlx_img = mlx_new_image(data->mlx.ptr, data->map_x, data->map_y);
	//put_image(data);
	mlx_hook(data->mlx.win, 02, (1L << 0), close_keys, data);
	mlx_hook(data->mlx.win, 17, (1L << 2), exit_game, data);
	mlx_loop(data->mlx.ptr);
}

void	init_data(t_data *data)
{
	data->c_ceiling = -1;
	data->c_floor = -1;
	data->gnl_x = 0;
	data->map_x = MAP_W;
	data->map_y = MAP_H;
	data->x = -1;
	data->y = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;
	(void)av;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (ac != 2)
	{
		free_data(data);
		return (write(1, "Error\n-Wrong number of args\n", 28));
	}
	init_data(data);
	create_matrix_map(data);
	//if (!parser(av, data))
	//free_data(data);
	init_window(data);
}
