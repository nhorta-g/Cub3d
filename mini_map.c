/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/09/27 15:15:39 by nhorta-g         ###   ########.fr       */
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
			if (data->map[x][y] == '0')
				draw_square(data, x * 40, y * 40, 40, MINIMAP_NO_COLOR);
			else if  (data->map[x][y] == '1')
				draw_square(data, x * 40, y * 40, 40, MINIMAP_COLOR_WALL);
		}
	}
	return (1);
}
