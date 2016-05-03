/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:42:26 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/03 00:58:54 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "libft.h"
# include <mlx.h>
# include "key.h"
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
# define MUL 67
# define DIV 75

typedef	struct	s_env
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
	float		tmp;
	float		imgx;
	float		imgy;
	float		x;
	float		y;
	int			ptr_x;
	int			ptr_y;
	int			pos_x;
	int			pos_y;
	int			i;
	int			ftype;
	int			bpp;
	int			len;
	int			endian;
	int			r;
	int			g;
	int			b;
	char		*data;
	void		*win;
	void		*mlx;
	void		*img;
}				t_env;

int				frac_type(int ac, char **av);
int				ft_mouse(int button, int a, int b, t_env *e);
int				motion_notif(int x, int y, t_env *e);
int				key_event(int keycode, t_env *e);
void			init_julia(t_env *e);
void			init_env(t_env *e, int ac, char **av);
void			set_mandle(t_env *e);
void			set_julia(t_env *e);
void			draw_img(t_env *e);
void			draw_mandle(t_env *e);
void			init_mandle(t_env *e);
void			init_boat(t_env *e);
void			draw_boat(t_env *e);
void			init_mlx(t_env *e);
void			draw_mix(t_env *e);
void			ft_connectm(t_env *e);
void			ft_connectt(t_env *e);
void			ft_connectb(t_env *e);
void			ft_connectj(t_env *e);
void			init_mj(t_env *e);
void			ft_opt();
void			set_color(t_env *e);
void			init_mix(t_env *e);
void			set_white(t_env *e);

#endif
