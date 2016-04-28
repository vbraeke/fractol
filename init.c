/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:57:07 by vbraeke           #+#    #+#             */
/*   Updated: 2016/04/27 15:57:08 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	key_event(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	(keycode == DOWN) ? e->max-- : 0;
	(keycode == UP) ? e->max++ : 0;
	(keycode == LESS) ? e->zoom-- : 0;
	(keycode == MORE) ? e->zoom++ : 0;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	set_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

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
	e->img = mlx_new_image(e->mlx, 600, 800);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	e->win = mlx_new_window(e->mlx, 700, 700, "Fractol");
}

void	init_env(t_env *e, int ac, char **av)
{
	e->r = 0;
	e->g = 0;
	e->b = 160;
	e->ftype = frac_type(ac, av);
	init_mlx(e);
	if (e->ftype == 2)
	{
		init_julia(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_key_hook(e->win, key_event, e);
	}
	else if (e->ftype == 1)
	{
		init_mandle(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_key_hook(e->win, key_event, e);
	}
	mlx_loop(e->mlx);
}


