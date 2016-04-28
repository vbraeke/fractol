/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:42:26 by vbraeke           #+#    #+#             */
/*   Updated: 2016/04/26 17:42:28 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "libft.h"
# include "mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53
# define SPACE 49
# define MORE 69
# define LESS 78

typedef	struct s_env
{
	float		zoom;
	float		max;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		z_r;
	float		z_i;
	float		c_r;
	float		c_i;
	float		i;
	float		tmp;
	float		imgx;
	float		imgy;
	float		x;
	float		y;

	int			ftype;
	int			bpp;
	int 		len;
	int			endian;
	int 		r;
	int 		g;
	int 		b;

	char		*data;

	void		*win;
	void		*mlx;
	void		*img;

}				t_env;

void	init_julia(t_env *e);
void	init_env(t_env *e, int ac, char **av);
int		frac_type(int ac, char **av);
void	set_mandle(t_env *e);
void	set_julia(t_env *e);
void	draw_img(t_env *e);
void	draw_mandle(t_env *e);
void	init_mandle(t_env *e);

#endif