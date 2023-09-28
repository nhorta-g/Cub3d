/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:24:04 by nhorta-g          #+#    #+#             */
/*   Updated: 2023/09/28 14:42:28 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	exit_game(t_data *data)
{
	free_all_data(data);
	exit(1);
}

int	close_keys(int key, t_data *data)
{
	if (key == ESC)
		exit_game(data);
	/*
	if (key == W)
		move_up();
	if (key == S)
		move_down();
	if (key == A)
		move_left();
	if (key == D)
		move_right();
	*/
	return (0);
}

