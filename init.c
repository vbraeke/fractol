/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:57:07 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/02 23:40:50 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	draw_img(t_env *e)
{
	int 	n;

	n = e->x * e->bpp / 8 + e->y * e->len;
	e->data[n] = e->r;
	e->data[n + 1] = e->g;
	e->data[n + 2] = e->b;
}

void	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, 500, 500);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	e->win = mlx_new_window(e->mlx, 500, 500, "Fractol");
}

void	set_color(t_env *e)
{
	if (e->r > 140)
		e->r = 10;
	if (e->r > 140)
		e->g =10;
	if (e->r > 140)
		e->b =10;
}

void	init_env(t_env *e, int ac, char **av)
{

	e->ftype = frac_type(ac, av);
	init_mlx(e);
	init_mj(e);

	else if (e->ftype == 3)
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
	mlx_loop(e->mlx);
}

void	init_mj(t_env *e)
{
	if (e->ftype == 2)
	{
		init_julia(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->pos_x, e->pos_y);
		mlx_key_hook(e->win, key_event, e);
		mlx_hook(e->win, 6, (1L << 6), motion_notif, e);
		mlx_mouse_hook(e->win, ft_mouse, e);

	}
	else if (e->ftype == 1)
	{
		init_mandle(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 1L << 0, key_event, e);
	x	mlx_mouse_hook(e->win, ft_mouse, e);

	}
}