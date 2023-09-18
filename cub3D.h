/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/19 00:15:04 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_player
{
	int		posX; // position vector of the player (X Y)
	int		posY;
	int		dirX; // direction of the player (X Y)
	int		dirY;

}	t_player;

typedef struct s_data
{
	char	**map;		// matriz com caracteres do mapa
	int		c_floor;	//cor chao
	int		c_ceiling;	//cor tecto
	char	*texture[4]; //as quartro strings com o path para o file de cada textura
	int		map_x;		//num colunas do input file dedicadas ao mapa, depois de text e cores
	int		map_y;		//num linhas do input file dedicadas ao mapa, depois de text e cores
	int		gnl_x;		//num linhas do input file dedicadas à textura e cores
	int		x;			//x coord of position in map matrix of the character
	int		y;			//y coord of position in map matrix of the character
	t_player *s_player;

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

//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char ***array);
int		free_data(t_data *data);

#endif