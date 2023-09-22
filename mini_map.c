/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/09/22 00:14:08 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_image(t_win	*win)
{
	int	x;
	int	y;

	x = -1;
	load_images(win);
	while (win->map[++x])
	{
		y = -1;
		while (win->map[x][++y])
		{
			mlx_put_image_to_window(win->mlx, win->win, \
			win->img[(win->map[x][y] == 'P') * 4 + \
			(win->map[x][y] == '0') * 5 + (win->map[x][y] == 'C') * 6 \
			+ (win->map[x][y] == 'E') * 7 + (win->map[x][y] == 'X') * 8] \
			, y * 48, x * 48);
		}
	}
}
