/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/10/24 13:00:29 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_map(t_data *d)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < d->mapY)
	{
		x = 0;
		while (x < d->mapX)
		{
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx.ptr, \
					d->mlx.win, d->mmap.wall, (x * (size_t)d->mmap.wall_w), (y * (size_t)d->mmap.wall_h));
			if (d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx.ptr, \
					d->mlx.win, d->mmap.empty, (x * (size_t)d->mmap.empty_w), (y * (size_t)d->mmap.empty_h));
			if (d->map[y][x] == 'N')
				mlx_put_image_to_window(d->mlx.ptr, \
					d->mlx.win, d->mmap.player, (x * (size_t)d->mmap.player_w), (y * (size_t)d->mmap.player_h));
			x++;
		}
		y++;
	}
}

int	image_minimap(t_data *d)
{
	d->mmap.text[0] = WALL;
	d->mmap.text[1] = EMPTY_SPAC;
	d->mmap.text[2] = PLAYER;
	d->mmap.wall = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[0], &d->mmap.wall_w, &d->mmap.wall_h);
		printf(" %d-%d ", d->mmap.wall_w, d->mmap.wall_h);
	d->mmap.empty = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[1], &d->mmap.empty_w, &d->mmap.empty_h);
		printf(" %d-%d ", d->mmap.empty_w, d->mmap.empty_h);
	d->mmap.player = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[2], &d->mmap.player_w, &d->mmap.player_h);
		printf(" %d-%d ", d->mmap.player_w, d->mmap.player_h);
	draw_map(d);
	return (0);
}
