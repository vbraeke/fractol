/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:33:42 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/02 23:23:35 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	key_event(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		ft_putendl("FRACT'OL QUIT");
		exit(0);
	}
	(keycode == LEFT) ? e->x1 += 0.1 : 0;
	(keycode == RIGHT) ? e->x1 -= 0.1 : 0;
	(keycode == DOWN) ? e->y1 += 0.1 : 0;
	(keycode == UP) ? e->y1 -= 0.1 : 0;
	(keycode == LESS) ? e->zoom -= 30 : 0;
	(keycode == MORE) ? e->zoom += 30 : 0;
	(keycode == MUL) ? e->max += 1 : 0;
	(keycode == DIV) ? e->max -= 1 : 0;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	(e->ftype == 1) ? draw_mandle(e) : 0;
	(e->ftype == 2) ? set_julia(e) : 0;
	(e->ftype == 3) ? draw_boat(e) : 0;
	(e->ftype == 4) ? draw_mix(e) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		ft_mouse(int button, int a, int b, t_env *e)
{
	if (button == 4 || button == 7)
		e->zoom += 30;
	if (button == 5 || button == 6)
		e->zoom -= 30;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	(e->ftype == 1) ? draw_mandle(e) : 0;
	(e->ftype == 2) ? set_julia(e) : 0;
	(e->ftype == 3) ? draw_boat(e) : 0;
	(e->ftype == 4) ? draw_mix(e) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}


int 	motion_notif(int x, int y, t_env *e)
{
	if (x < 250 && x > 0 && y < 500 && y > 0)
	{
		e->c_i -= 0.01;
		e->c_r += 0.01;
	}
	if (x > 250 && x < 500 && y < 500 && y > 0)
	{
		e->c_i += 0.01;
		e->c_r -= 0.01;
	}
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	free(e->data);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	(e->ftype == 2) ? set_julia(e) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}