/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:33:41 by nuno              #+#    #+#             */
/*   Updated: 2023/10/24 12:50:05 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*pixel;

	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	pixel = d->img.addr + y * d->img.line_len + x * (d->img.bpp / 8);
	*(unsigned int*)pixel = color;
	printf("addr: %s ", d->img.addr);
	printf("line_len: %s ", d->img.addr);
	printf("img_bpp: %d ", d->img.bpp);
	printf("pixel: %s ", pixel);
}

void	draw_square(t_data *d, int pos_x, int pos_y, int size, int color)
{
	int x;
	int y;

	x = -1;
	while (x++ <= size)
	{
		y = -1;
		while(y++ <= size)
			mlx_pixel_put(d->mlx.ptr, d->mlx.win, pos_x + x, pos_y + y, color);
	}
}
