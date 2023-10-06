/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/10/06 16:26:15 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_map(t_data *d)
{
	size_t x;
	size_t y;
	size_t s;

	s = (size_t)d->mmap.s;
	printf("\n\nsize: %ld\n\n", s);
	y = 0;
	while (y < d->map_y)
	{
		x = 0;
		while (x < d->map_x)
		{
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx.ptr, \
					d->mlx.win, d->mmap.wall, (x * s), (y * s));
			if (d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx.ptr, \
					d->mlx.win, d->mmap.empty, (x * s), (y * s));
			x++;
		}
		y++;
	}
}

int	image_minimap(t_data *d)
{
	d->mmap.wall = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[0], &d->mmap.s, &d->mmap.s);
	d->mmap.empty = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[1], &d->mmap.s, &d->mmap.s);
	d->mmap.player = mlx_xpm_file_to_image(d->mlx.ptr, \
		d->mmap.text[2], &d->mmap.s, &d->mmap.s);
	draw_map(d);
	return (0);
}
