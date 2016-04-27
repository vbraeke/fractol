/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:50:06 by vbraeke           #+#    #+#             */
/*   Updated: 2016/04/27 17:50:07 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	init_mandle(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 100;
	e->max = 50;
}

void	draw_mandle(t_env *e)
{
	float x;
	float y;

	e->imgx = (e->x2 - e->x1) * e->zoom;
	e->imgy = (e->y2 - e->y1) * e->zoom;

	x = 0;
	y = 0;
	while (x < e->imgx)
	{
		while (y < e->imgy)
		{
			e->c_r = x / e->zoom + x1;
			e->c_i = y / zoom + y1
			e->z_i = 0;
			e->z_r = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if()
			{

			}
			else if()
			{

			}
			y++;
		}
		x++;
	}
}

