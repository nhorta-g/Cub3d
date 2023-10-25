/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:52 by nuno              #+#    #+#             */
/*   Updated: 2023/10/25 21:01:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_walls_2(t_data *d, int x, int y)
{
	if (d->side == 0 && \
	d->map[d->playerY][d->playerX] == '1')
	{
		if (d->playerX < d->posX)
			d->buffer[y][x] = d->texture[2] \
			[d->cub_size * d->textureY + d->textureX];
		else
			d->buffer[y][x] = d->texture[3] \
			[d->cub_size * d->textureY + d->textureX];
	}
	else if (d->side == 1 && \
	d->map[d->playerY][d->playerX] == '1')
	{
		if (d->playerY < d->posY)
			d->buffer[y][x] = d->texture[1] \
			[d->cub_size * d->textureY + d->textureX];
		else
			d->buffer[y][x] = d->texture[0] \
			[d->cub_size * d->textureY  + d->textureX];
	}
}

static void	print_walls(t_data *d, int x, int y)
{
	if (d->angle == 0 || d->angle == 270)
	{
		if (d->side == 0 && \
		d->map[d->playerY][d->playerX] == '1')
		{
			if (d->playerX < d->posX)
				d->buffer[y][x] = d->texture[3] \
				[d->cub_size * d->textureY + d->textureX];
			else
				d->buffer[y][x] = d->texture[2] \
				[d->cub_size * d->textureY + d->textureX];
		}
		else if (d->side == 1 && \
		d->map[d->playerY][d->playerX] == '1')
		{
			if (d->playerY < d->posY)
				d->buffer[y][x] = d->texture[0] \
				[d->cub_size * d->textureY + d->textureX];
			else
				d->buffer[y][x] = d->texture[1] \
				[d->cub_size * d->textureY + d->textureX];
		}
	}
	if (d->angle == 90 || d->angle == 180)
		print_walls_2(d, x, y);
}

void	textures_wall(t_data *d, int x)
{
	int	y;

	d->textureX = (int)(d->wallX * d->cub_size);
	if (d->side == 0 && d->rayDirX > 0)
		d->textureX = d->cub_size - d->textureX - 1;
	if (d->side == 1 && d->rayDirY < 0)
		d->textureX = d->cub_size - d->textureX - 1;
	d->step = 1.0 * d->cub_size / d->lineHeight;
	d->texture_position = (d->drawStart - d->mlx.win_height / 2 + \
	d->lineHeight / 2) * d->step;
	y = d->drawStart;
	while (y < d->drawEnd)
	{
		d->textureY = (int)d->texture_position & \
		(d->cub_size - 1);
		d->texture_position += d->step;
		print_walls(d, x, y);
		y++;
	}
}

void	vertical_line(t_data *d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < d->mlx.win_height)
	{
		x = -1;
		while (++x < d->mlx.win_width)
			d->img.addr[y * d->mlx.win_width + x] = d->buffer[y][x];
	}
	mlx_put_image_to_window(d->mlx.ptr, d->mlx.win, d->img.img, 0, 0);
}
