/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:56:28 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/02 23:44:22 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	set_julia(t_env *e)
{
	e->imgx = 500;
	e->imgy = 500;
	
	e->x = 0;
	while (e->x < e->imgx)
	{

			e->y = 0;
		while (e->y < e->imgy)
		{
			
			e->z_i = e->y / e->zoom + e->y1;
			e->z_r = e->x / e->zoom + e->x1;
			e->i = 0;
			ft_connectj(e);
			e->y++;
		}
		e->x++;
	}
}

void	ft_connectj(t_env *e)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
		if(e->i == e->max)
		{
		
			draw_img(e);

		}
		else
		{	
			if (e->i % 2 == 0 )
			{
				e->r = 0;
				e->g = e->i * 180 / e->max;
				e->b = e->i * 30 / e->max;
				draw_img(e);

			}	
			else
			{
				e->r = 1;
				e->g = 1;
				e->b = 1;
				draw_img(e);

			}
		}
	}
}

void	init_julia(t_env *e)
{
	e->c_r = -0.70;
	e->c_i = 0.27015;
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->x1 = -1.3;
	e->x2 = 2;
	e->y1 = -1.2;
	e->y2 = 2;
	e->zoom = 250;
	e->max = 10;
	e->pos_x = 0;
	e->pos_y = 0;
	set_julia(e);
}
