/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:33:41 by nuno              #+#    #+#             */
/*   Updated: 2023/09/27 16:09:59 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= MAP_H || y >= MAP_H || x < 0 || y < 0)
		return ;
	pixel = data->img.addr + y * data->img.line_len + x * (data->img.bpp / 8);
	*(unsigned int*)pixel = color;
	printf("addr: %s ", data->img.addr);
	printf("line_len: %s ", data->img.addr);
	printf("img_bpp: %d ", data->img.bpp);
	printf("pixel: %s ", pixel);
}

void	draw_square(t_data *data, int pos_x, int pos_y, int size, int color)
{
	int x;
	int y;

	x = -1;
	while (x++ <= size)
	{
		y = -1;
		while(y++ <= size)
			mlx_pixel_put(data->mlx.ptr, data->mlx.win, pos_x + x, pos_y + y, color);
	}
}