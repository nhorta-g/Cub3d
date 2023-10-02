/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:35 by nuno              #+#    #+#             */
/*   Updated: 2023/09/29 12:30:19 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	image_minimap(t_data *data)
{
	data->mmap.size = 20;
	data->mmap.wall = mlx_xpm_file_to_image(data->texture[0]);
	data->mmap.empty = 0;
	data->mmap.player = 0;
}
