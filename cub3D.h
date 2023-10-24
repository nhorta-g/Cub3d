/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/24 13:00:29 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "./mlx_linux/mlx.h"

//RESOLUTION and sizes
# define WIN_W		1080
# define WIN_H		720
# define CUBE_SIZE	64
# define MINI_MAP_SIZE 10

//MINIMAP TEXTURES
# define WALL		"./textures/redbrick_64.xpm";
# define EMPTY_SPAC	"./textures/Relva_64.xpm";
# define PLAYER		"./textures/Ash_front_64.xpm";

//kEYS
# define ESC		65307
# define A 			97
# define D			100
# define S			115
# define W			119



typedef struct s_img
{
	void		*mlx_img;	//image pointer
	char		*addr;
	int			bpp;		//bits per pixel
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_mlx
{
	void		*ptr;		//mlx_init pointer
	void		*win;		//window pointer
	int			win_width;
	int			win_height;
}	t_mlx;

typedef struct s_mmap
{
	int			s;			//map size
	void		*wall;
	int			wall_w;
	int			wall_h;
	void		*empty;		//void pointer to textures
	int			empty_w;
	int			empty_h;
	void		*player;
	int			player_w;
	int			player_h;
	char		*text[3];	//paths textures
}	t_mmap;

typedef struct s_data
{

	char		**map;		// matriz com caracteres do mapa
	int			c_floor;	//cor chao
	int			c_ceiling;	//cor tecto
	char		*texture[4]; //strings com o path para o file de cada textura NO/SO/EA/WE
	size_t		mapX;		//num colunas do input file dedicadas ao mapa, depois de text e cores
	size_t		mapY;		//num linhas do input file dedicadas ao mapa, depois de text e cores
	size_t		gnl_x;		//num linhas do input file dedicadas à textura e cores
	int			x;			//x coord of position in map matrix of the character
	int			y;			//y coord of position in map matrix of the character
	double		posX;		//A mm coord do player mas double
	double		posY;		//A mm coord do player mas double
	int			cub_size;	//Comprimento em pixeis de cada aresta de um cubo
	int			hit;
	int			buffer[WIN_H][WIN_W];
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	int			stepX;
	int			stepY;
	t_mlx		mlx;
	t_img		img;
	t_mmap		mmap;

}	t_data;

//parser.c
int			parser(char **av, t_data *data);

//parser_utils.c
int			fill_textures(t_data *data, char *line, int i, int index);
int			fill_colours(t_data *data, char *line, int i, int index);
int			check_done(t_data *data);
int			alloc_map(t_data *data, char **av);

//parser_utils_2.c
int			fill_map(char **av, t_data *data);
int			validate_map(t_data *data);
char		*skip_empty_lines(char *buffer, int *mapfd);
int			check_file_format(char **av, t_data *data);
int			return_free(char *buff);

//validate_map_utils.c
int			check_walls(t_data *data, int j, int i);

//utils.c
int			skip_spaces(char *str, int i);
int			print_error(char *str);
int			free_double(char **array);
int			free_data(t_data *data);
int			free_all_data(t_data *data);
void		perror_exit(char *msg, int code);
void		perror_exit_free_all_data(t_data *data, char *msg, int code);

//raycasting.c
void		init_vars(t_data *d);
int			start_raycasting(void *data_src);

//init_ray.c
void		init_ray(t_data *d, int x);

//hooks.c
int			close_keys(int key, t_data *d);
int			exit_game(t_data *d);

//mini_map.c
int			image_minimap(t_data *d);

//draw_utils.c
void		my_mlx_pixel_put(t_data *d, int x, int y, int color);
void		draw_square(t_data *d, int pos_x, int pos_y, int size, int color);

int			temporary_parser(t_data *d);

#endif
