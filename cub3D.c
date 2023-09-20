/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/19 12:36:16 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	data->c_ceiling = -1;
	data->c_floor = -1;
	data->gnl_x = 0;
	data->map_x = 0;
	data->x = -1;
	data->y = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)calloc(1, sizeof(t_data));
	if (ac != 2)
		return (write(1, "Error\n-Wrong number of args", 27));
	init_data(data);
	init_map(&data, argv[1]);
	if (!parser(av, data))
		free_data(data);
}
