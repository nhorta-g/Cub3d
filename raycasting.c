/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:40:09 by nuno              #+#    #+#             */
/*   Updated: 2023/10/23 19:23:57 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.c"

/*Inicializa variaveis do jogo*/
void	init_vars(t_data *d)
{
	d->mlx.win_width = WIN_W;
	d->mlx.win_height = WIN_H;
	d->cub_size = CUBE_SIZE;
	/*render->dir_x = (-1.0 * (render->angle == 90)) + \
	((render->angle == 270) + 0.1);
	render->dir_y = (-1.0 * (render->angle == 0)) + (render->angle == 180);
	render->plane_y = 0.66 * ((render->angle == 270)) + (render->angle == 90);
	render->plane_x = 0.66 * ((render->angle == 0)) + (render->angle == 180);
	render->mv_speed = 0.05;
	render->rt_speed = 0.05;
	render->ceiling_text = check_colour(this()->ceiling);
	render->floor_text = check_colour(this()->floor);*/
}

/*Escreve num buffer, render->**buffer as texturas do tecto para
a metade superior da win_height e do chao para a metade inferior*/
static void	draw_back(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d->mlx.win_height)
	{
		x = 0;
		while (y < d->mlx.win_height / 2 && x < d->mlx.win_width)
		{
			d->buffer[y][x] = d->c_ceiling;
			x++;
		}
		x = 0;
		while (y > d->mlx.win_height / 2 && x < d->mlx.win_width)
		{
			d->buffer[y][x] = d->c_floor;
			x++;
		}
		y++;
	}
}

/*Executa o rendering de cada linha vertical de x = 0 a win_width;
init_ray: inicializa o raio e envia nas direcoes correctas, vê se
encontrou a parede, draw size, save draw numbers e texturas parede*/
void	rendering(t_data *d)
{
	int	x;

	x = -1;
	while (++x < d->mlx.win_width)
	{
		init_ray(d, x);
		d->hit = 0;
		while (d->hit == 0)
			find_hit_wall(d);
		draw_size(d);
		save_draw_numbers(d);
		textures_wall(d, x);
	}
}

/*Comeca o raycasting*/
int start_raycasting(void *data_src)
{
	t_data *d;
	d = (t_data *)data_src;
	draw_back(d);
	rendering(d);
	//vertical_line(d);

	return (0);
}
