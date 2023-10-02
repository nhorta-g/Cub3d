/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/10/02 15:56:39 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map(t_data *data)
{
	int x;
	int y;

	x = -1;
	while (++x <= data.map_x)
	{
		y = -1;
		while (++j <= data.map_y)
			if (data->map[] ==)mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mmap.wall, x, y);
	}
}

int	image_minimap(t_data *data)
{
	data->mmap.size = 20;
	data->mmap.wall = mlx_xpm_file_to_image(data->mlx.ptr, data->mmap.texture[0]);
	data->mmap.empty = mlx_xpm_file_to_image(data->mlx.ptr, data->mmap.texture[1]);
	data->mmap.player = mlx_xpm_file_to_image(data->mlx.ptr, data->mmap.texture[2]);
	draw_map(data);
	return (0);
}
