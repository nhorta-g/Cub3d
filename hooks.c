/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:24:04 by nhorta-g          #+#    #+#             */
/*   Updated: 2023/09/27 20:50:26 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	exit_game(void)
{
	free_all_data(data);
	exit(1);
}

int	hook(t_data *data, int key)
{
	int	move;

	move = 0;
	if (key == ESC)
		exit_game(data);
	if (key == W)
		move = move_up();
	if (key == S)
		move = move_down();
	if (key == A)
		move = move_left();
	if (key == D)
		move = move_right();
	return (move);
}

