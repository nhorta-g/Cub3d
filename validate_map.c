/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:42 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/25 13:45:07 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	add_spaces(t_data *data, int j)
{
	while (ft_strlen(data->map[j]) < data->map_x)
		data->map[j] = ft_strjoin_free(data->map[j], " ");
}

void	rectify_shape(t_data *data)
{
	int	i;
	int	j;

	i = data->map_y;
	j = 0;
	while (i >= 0 && data->map[j])
	{
		if (ft_strlen(data->map[j]) < data->map_x)
			add_spaces(data, j);
		i--;
		j++;
	}
}

int	check_illegal(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ')
		return (1);
	return (0);
}

int	check_dupe(char c, t_data *data, int i, int j)
{
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& (data->x == -1 && data->y == -1))
	{
		data->x = j;
		data->y = i;
	}
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& (data->x != -1 && data->y != -1))
		return (1);
	return (0);
}

int	validate_map(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	rectify_shape(data);
	while (data->map[i])
	{
		while (data->map[j])
		{
			if (check_illegal(data->map[i][j])
				|| check_dupe(data->map[i][j], data, i, j))
				return (print_error("illegal char in map or char duped"));
			if (data->map[i][j] == '0')
				if (check_walls(data, i, j))
					return (print_error("invalid map: unclosed"));
			j++;
		}
		i++;
	}
	return (0);
}
