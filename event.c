/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:33:42 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/03 00:03:10 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	draw_img(t_env *e)
{
	int		n;

	n = e->x * e->bpp / 8 + e->y * e->len;
	e->data[n] = e->r;
	e->data[n + 1] = e->g;
	e->data[n + 2] = e->b;
}

void	ft_reset(t_env *e)
{
	(e->ftype == 1) ? init_mandle(e) : 0;
	(e->ftype == 2) ? init_julia(e) : 0;
	(e->ftype == 3) ? init_boat(e) : 0;
	(e->ftype == 4) ? init_mix(e) : 0;
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
	e->r = e->i * 255 / e->max;
	e->g = e->i * 255 / e->max;
	e->b = e->i * 255 / e->max;
}
