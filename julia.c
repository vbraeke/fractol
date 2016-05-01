/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:56:28 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/01 02:01:12 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	set_julia(t_env *e)
{
	e->imgx = 800;
	e->imgy = 800;
	
	e->x = 0;
	while (e->x < e->imgx)
	{

			e->y = 0;
		while (e->y < e->imgy)
		{
			e->c_r = 0.285;
			e->c_i = 0.01;
			e->z_i = e->y / e->zoom + e->y1;
			e->z_r = e->x / e->zoom + e->x1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
				if(e->i == e->max)
				{
					e->r = 0;
					e->g = 0;
					e->b = 0;
					draw_img(e);
					e->r = 0;
					e->g = 0;
					e->b = 0;
				}
				else
				{	
					if (e->i % 2 == 0 )
					{
						e->r = e->i * 30 / e->max;
						e->g = e->i * 100 / e->max;
						e->b = e->i * 30 / e->max;
						draw_img(e);
						e->r = 0;
						e->g = 0;
						e->b = 0;
					}	
					else
					{
						e->r = e->i * 100 / e->max;
						e->g = e->i * 100 / e->max;
						e->b = e->i * 100 / e->max;
						draw_img(e);
						e->r = 0;
						e->g = 0;
						e->b = 0;
					}
				
				}
			}
			e->y++;
		}
		e->x++;
	}
}

void	init_julia(t_env *e)
{
	e->r = e->i * 100 / e->max;
	e->g = e->i * 100 / e->max;
	e->b = e->i * 100 / e->max;
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -2;
	e->y2 = 1.2;
	e->zoom = 300;
	e->max = 150;
	e->pos_x = 0;
	e->pos_y = 0;
	set_julia(e);
}
