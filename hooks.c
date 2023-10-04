/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:24:04 by nhorta-g          #+#    #+#             */
/*   Updated: 2023/10/03 15:27:13 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	exit_game(t_data *d)
{
	free_all_data(d);
	exit(1);
}

int	close_keys(int key, t_data *d)
{
	if (key == ESC)
		exit_game(d);
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

