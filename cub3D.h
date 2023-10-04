/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/04 15:41:49 by nuno             ###   ########.fr       */
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
# define MAP_W		1080
# define MAP_H		720

# define MINI_MAP_SIZE 5

//MINIMAP TEXTURES
# define WALL		"./textures/bricks.xpm"
# define EMPTY_SPAC	"./textures/blanck.xpm"
# define PLAYER		"./textures/rug								"

//kEYS
# define ESC		65307
# define A 			97
# define D			100
# define S			115
# define W			119

typedef struct s_mlx
{
	void		*ptr;
	void		*win;

}	t_mlx;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_player
{
	int			posX; 		// position vector of the player (X Y)
	int			posY;
	int			dirX;		// direction of the player (X Y)
	int			dirY;
}	t_playr;

typedef struct s_mmap
{
	int			s;			//map size
	void		*wall;
	void		*empty;		//void pointer to textures
	void		*player;
	char		*text[3];	//paths textures
}	t_mmap;

typedef struct s_data
{

	char		**map;		// matriz com caracteres do mapa
	int			c_floor;	//cor chao
	int			c_ceiling;	//cor tecto
	char		*texture[4]; //as quartro strings com o path para o file de cada textura
	size_t		map_x;		//num colunas do input file dedicadas ao mapa, depois de text e cores
	size_t		map_y;		//num linhas do input file dedicadas ao mapa, depois de text e cores
	size_t		gnl_x;		//num linhas do input file dedicadas à textura e cores
	int			x;			//x coord of position in map matrix of the character
	int			y;			//y coord of position in map matrix of the character
	t_playr		player;
	t_mlx		mlx;
	t_img		img;
	t_mmap		mmap;

}	t_data;

//parser.c
int		parser(char **av, t_data *data);

//parser_utils.c
int		fill_textures(t_data *data, char *line, int i, int index);
int		fill_colours(t_data *data, char *line, int i, int index);
int		check_done(t_data *data);
int		alloc_map(t_data *data, char **av);

//parser_utils_2.c
int		fill_map(char **av, t_data *data);
int		validate_map(t_data *data);

//validate_map_utils.c
int		check_walls(t_data *data, int j, int i);

//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char **array);
int		free_data(t_data *data);
int		free_all_data(t_data *data);
void	perror_exit(char *msg, int code);
void	perror_exit_free_all_data(t_data *data, char *msg, int code);

//hooks
int		close_keys(int key, t_data *d);
int		exit_game(t_data *d);

//mini_map.c
int		image_minimap(t_data *d);

//draw_utils.c
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
void	draw_square(t_data *d, int pos_x, int pos_y, int size, int color);

int		temporary_parser(t_data *d);

#endif
