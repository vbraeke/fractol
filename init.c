/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:57:07 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/03 01:11:47 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		ft_mouse(int button, int a, int b, t_env *e)
{
	int		tmp1;
	int		tmp2;

	tmp1 = a;
	tmp2 = b;
	if (button == 4 || button == 7)
		e->zoom += 30;
	if (button == 5 || button == 6)
		e->zoom -= 30;
	free(e->data);
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	(e->ftype == 1) ? draw_mandle(e) : 0;
	(e->ftype == 2) ? set_julia(e) : 0;
	(e->ftype == 3) ? draw_boat(e) : 0;
	(e->ftype == 4) ? draw_mix(e) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_event(int keycode, t_env *e)
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
	free(e->data);
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	(e->ftype == 1) ? draw_mandle(e) : 0;
	(e->ftype == 2) ? set_julia(e) : 0;
	(e->ftype == 3) ? draw_boat(e) : 0;
	(e->ftype == 4) ? draw_mix(e) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		motion_notif(int x, int y, t_env *e)
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

void	init_mj(t_env *e)
{
	if (e->ftype == 2)
	{
		init_julia(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_key_hook(e->win, key_event, e);
		mlx_hook(e->win, 6, (1L << 6), motion_notif, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
	}
	else if (e->ftype == 1)
	{
		init_mandle(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 1L << 0, key_event, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
	}
}

void	init_env(t_env *e, int ac, char **av)
{
	e->ftype = frac_type(ac, av);
	init_mlx(e);
	ft_opt();
	if (e->ftype == 3)
	{
		init_boat(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 1L << 0, key_event, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
	}
	else if (e->ftype == 4)
	{
		init_mix(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 1L << 0, key_event, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
	}
	init_mj(e);
	mlx_loop(e->mlx);
}
