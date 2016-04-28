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


void	draw_mandle(t_env *e)
{
	e->imgx = (e->x2 - e->x1) * e->zoom;
	e->imgy = (e->y2 - e->y1) * e->zoom;
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
					e->r = 0;
					e->g = 0;
					e->b = e->i * 255 / e->max;
					draw_img(e);
					e->r = 0;
					e->g = 0;
					e->b = 0;
				
				}
			}
			e->y++;
		}
		e->x++;
	}
}

//dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)

void	init_mandle(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 2.1;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 260;
	e->max = 50;
	draw_mandle(e);
}
