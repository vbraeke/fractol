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

typedef	struct s_env
{
	int			ftype;
	void		*win;
	void		*mlx;
}				t_env;

typedef struct	s_data
{

}				t_data;

void	error_arg(int n);
int		frac_type(int ac, char **av);
#endif