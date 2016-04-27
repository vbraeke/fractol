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

int	key_event(int keycode, void *param)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, 1000, 800);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	e->win = mlx_new_window(e->mlx, 1000, 800, "Fractol");
}

void	init_env(t_env *e, int ac, char **av)
{
	e->ftype = frac_type(ac, av);
	e->mlx = mlx_init();
	if (e->ftype == 2)
	{
		init_julia(e);
	}
	else if (e->ft_type == 1)
	{
		init_mand(e)
	}
	init_mlx(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, key_event, 0);
	mlx_loop(e->mlx);
}


