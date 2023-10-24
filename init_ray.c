/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:29:24 by nuno              #+#    #+#             */
/*   Updated: 2023/10/24 13:00:29 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

static void	calc_step_initial_sideDIst(t_data *d)
{
	if (d->rayDirX < 0)
	{
		d->stepX = -1;
		d->sideDistX = ((d->posX - d->mapX) \
		* d->deltaDistX);
	}
	else
	{
		d->stepX = 1;
		d->sideDistX = ((d->mapX + 1.0 - d->posX) \
		* d->deltaDistX);
	}
	if (d->rayDirY < 0)
	{
		d->stepY = -1;
		d->sideDistY = ((d->posY - d->mapY) \
		* d->deltaDistY);
	}
	else
	{
		d->stepY = 1;
		d->sideDistY = ((d->mapY + 1.0 - d->posY) \
		* d->deltaDistY);
	}
}

/*inicializa o raio e envia nas direcoes correctas*/
void	init_ray(t_data *d, int x)
{
	d->cameraX = ((2 * x) / (double)(WIN_W) - 1);
	d->rayDirX = d->dirX + d->planeX * d->cameraX;
	d->rayDirY = d->dirY + d->planeX * d->cameraX;
	d->mapX = (int)d->x;
	d->mapY = (int)d->y;
	d->deltaDistX = fabs(1 / d->rayDirX);
	d->deltaDistY = fabs(1 / d->rayDirY);
	calc_step_initial_sideDIst(d);
}

