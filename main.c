/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:41:49 by vbraeke           #+#    #+#             */
/*   Updated: 2016/05/03 01:15:30 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	error_arg(int n)
{
	if (n == 0)
		ft_putstr("No paramater found\n\n");
	else
		ft_putstr("Incorrect paramater\n");
	ft_putstr("FRACT'OL : Please reboot this program with one");
	ft_putstr(" of the following parameter :\n");
	ft_putstr("M for Mandelbrot\nJ for Julia\n");
	ft_putstr("B for Boat\nT for a mix of Mandelbrot and Newton");
	exit(EXIT_FAILURE);
}

int		frac_type(int ac, char **av)
{
	if (ac != 2)
		error_arg(0);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'B')
		return (3);
	else if (av[1][0] == 'T')
		return (4);
	error_arg(1);
	return (0);
}

void	ft_opt(void)
{
	ft_putendl("\nFRACT_OL OPTIONS:");
	ft_putendl("\nZOOM +                 : 'SCROLL UP' or '*'");
	ft_putendl("ZOOM -                 : 'SCROLL DOWN' or '/'");
	ft_putendl("MOVE UP                : 'KEY UP'");
	ft_putendl("MOVE DOWN              : 'KEY DOWN'");
	ft_putendl("MOVE RIGHT             : 'KEY RIGHT'");
	ft_putendl("MOVE LEFT              : 'KEY LEFT'");
	ft_putendl("CLEARNESS +            : '+'");
	ft_putendl("CLEARNESS -            : '-'");
	ft_putendl("RESET BASE PARAMETER    : 'SPACE'");
	ft_putendl("\nFOR JULIA FRACTAL:");
	ft_putendl("\nMOUSE MOTION NOTIFY    : MOUSE ROTATION 'LEFT' and 'RIGHT'");
}

int		main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);
	return (0);
}
