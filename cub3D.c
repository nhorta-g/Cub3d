/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/06 15:47:39 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_data *d)
{
	d->mlx.ptr = mlx_init();
	if (!d->mlx.ptr)
		perror_exit_free_all_data(d, "Error establishing connection to graphical system", 1);
	d->mlx.win = mlx_new_window(d->mlx.ptr, MAP_W, MAP_H, "Cub3d");
	if (!d->mlx.win)
		perror_exit_free_all_data(d, "Error creating window", 1);
	image_minimap(d);
	mlx_hook(d->mlx.win, 02, (1L << 0), close_keys, d);
	mlx_hook(d->mlx.win, 17, (1L << 2), exit_game, d);
	mlx_loop(d->mlx.ptr);
}

void	init_data(t_data *d)
{
	d->c_ceiling = -1;
	d->c_floor = -1;
	d->gnl_x = 0;
	d->map_x = 0;
	d->map_y = 0;
	d->x = -1;
	d->y = -1;
	d->mmap.s = MINI_MAP_SIZE;
}

int	main(int ac, char **av)
{
	t_data	*d;
	(void)av;
	int		i;

	d = (t_data *)ft_calloc(1, sizeof(t_data));
	if (ac != 2)
	{
		free_data(d);
		return (write(1, "Error\n-Wrong number of args\n", 28));
	}
	init_data(d);
	temporary_parser(d);
	/*if (parser(av, d))
	{
		i = -1;
		while (d->map[++i])
			printf(":%s:\n", d->map[i]);
		free_data(d);
		return (1);
	}*/

	for (size_t k = 0; k < d->map_y; k++)
	{
		for (size_t l = 0; l < d->map_x; l++)
			printf("%d ", d->map[k][l]);
		printf("\n");
	}
	i = -1;
	while (d->map[++i])
		printf(":%s:\n", d->map[i]);
	init_mlx(d);
	free_data(d);
	return (0);
}
