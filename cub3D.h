/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/12 15:42:38 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_data
{
	char	**map;
	int		c_floor;
	int		c_ceiling;
	char	texture[4];
	int		gnl_x;
	int		x;
	int		y;
	t_player *s_player;

}	t_data;

typedef struct s_player
{
	int		posX; // position vector of the player (X Y)
	int		posY;
	int		dirX; // direction of the player (X Y)
	int		dirY;

}	t_player;
 
//parser.c
int		parser(int ac, char **av, t_data *data);

//parser_utils.c
int		fill_textures(t_data *data, char *line, int i, int index);
int		fill_colours(t_data *data, char *line, int i, int index);
int		check_done(t_data *data);


//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char ***array);

#endif
