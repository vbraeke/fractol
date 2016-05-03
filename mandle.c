/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:50:06 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/02 23:22:27 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	draw_mandle(t_env *e)
{
	e->imgx = 500;
	e->imgy = 500;
	e->x = 0;
	while (e->x < e->imgx)
	{
		e->y = 0;
		while (e->y < e->imgy)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_i = 0;
			e->z_r = 0;
			e->i = 0;
			ft_connectm(e);
			e->y++;
		}
		e->x++;
	}
}

void	check_colorm(t_env *e)
{
	if (e->i % 2 == 0)
	{
		set_color(e);
		draw_img(e);
	}
	else
	{
		e->r = 0;
		e->g = 0;
		e->b = e->i * 255 / e->max;
		draw_img(e);
	}
}

void	ft_connectm(t_env *e)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
		if (e->i == e->max)
		{
			e->r = 0;
			e->g = 0;
			e->b = 130;
			draw_img(e);
		}
		else
			check_colorm(e);
	}
}

void	init_mandle(t_env *e)
{
	e->x1 = -1.7;
	e->x2 = 1.0;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 230;
	e->max = 15;
	draw_mandle(e);
}
