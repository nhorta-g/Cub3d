/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/09/22 15:47:41 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	put_image(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	//load_images(win);
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, \
			data[(win->map[x][y] == 'P') * 4 + \
			(win->map[x][y] == '0') * 5 + (win->map[x][y] == 'C') * 6 \
			+ (win->map[x][y] == 'E') * 7 + (win->map[x][y] == 'X') * 8] \
			, y * 48, x * 48);
		}
	}
}

