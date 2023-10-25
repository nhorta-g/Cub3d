/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:29:24 by nuno              #+#    #+#             */
/*   Updated: 2023/10/25 20:29:50 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

/*perform DDA, first jump to next map square, either in x-direction, or in
y-direction than check if ray has hit a wall*/
void		find_hit_wall(t_data *d)
{
	if (d->sideDistX < d->sideDistY)
	{
		d->sideDistX += d->deltaDistX;
		d->playerX += d->stepX;
		d->side = 0;
	}
	else
	{
		d->sideDistY += d->deltaDistY;
		d->map += d->stepY;
		d->side = 1;
	}
	if (d->map[d->playerY][d->playerX] == '1')
		d->hit = 1;
}

/*Calculate perpWallDist, distance projected on camera direction than
calculats lineHeight, height of line to draw on screen and than calculats
lowest and highest pixel to fill in current stripe*/
void		draw_size(t_data *d)
{
	if (d->side == 0)
		d->perpWallDist = (d->sideDistX - d->deltaDistX);
	else
		d->perpWallDist = (d->sideDistY - d->deltaDistY);
	d->lineHeight = (int)(d->mlx.win_height / d->perpWallDist);
	d->drawStart = ((-d->lineHeight / 2) + (d->mlx.win_height / 2));
	if (d->drawStart < 0)
		d->drawStart = 0;
	d->drawEnd = ((d->lineHeight / 2) + (d->mlx.win_height / 2));
	if (d->drawEnd > d->mlx.win_height)
		d->drawEnd = d->mlx.win_height - 1;
}

/*Calculate wallX, exact point of the wall where it was hit*/
void	calculate_wall_hit(t_data *d)
{
	if (d->side == 0)
		d->wallX = d->posY + d->perpWallDist * d->rayDirY;
	else
		d->wallX = d->posX + d->perpWallDist * d->rayDirX;
	d->wallX -= floor(d->wallX);
}

/*calculate step and initial sideDist: if the ray direction has a negative
x-component, stepX is -1, the same for Y component*/
static void	calc_step_initial_sideDIst(t_data *d)
{
	if (d->rayDirX < 0)
	{
		d->stepX = -1;
		d->sideDistX = ((d->posX - d->playerX) \
		* d->deltaDistX);
	}
	else
	{
		d->stepX = 1;
		d->sideDistX = ((d->posX + 1.0 - d->playerX) \
		* d->deltaDistX);
	}
	if (d->rayDirY < 0)
	{
		d->stepY = -1;
		d->sideDistY = ((d->posY - d->playerY) \
		* d->deltaDistY);
	}
	else
	{
		d->stepY = 1;
		d->sideDistY = ((d->playerY + 1.0 - d->posY) \
		* d->deltaDistY);
	}
}

/*inicializa o raio e envia nas direcoes correctas*/
void		init_ray(t_data *d, int x)
{
	d->cameraX = ((2 * x) / (double)(WIN_W) - 1);
	d->rayDirX = d->dirX + d->planeX * d->cameraX;
	d->rayDirY = d->dirY + d->planeX * d->cameraX;
	d->playerX = (int)d->posX;
	d->playerY = (int)d->posY;
	d->deltaDistX = fabs(1 / d->rayDirX);
	d->deltaDistY = fabs(1 / d->rayDirY);
	calc_step_initial_sideDIst(d);
}

