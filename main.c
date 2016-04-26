/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:41:49 by vbraeke           #+#    #+#             */
/*   Updated: 2016/04/26 17:41:51 by vbraeke          ###   ########.fr       */
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
	ft_putstr("M for Mandelbrot\nJ for Julia\nN for Newton\n");
	exit(EXIT_FAILURE);
}

int		frac_type(int ac, char **av)
{
	if (ac < 2)
		error_arg(0);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'N')
		return (3);
	error_arg(1);
	return (0);
}

void	init_env(t_env *e, int ac, char **av)
{
	e->ftype = frac_type(ac, av);
	e->mlx = mlx_init();
	// if (e->ftype == 1)
	// {

	// }	//ft_mand();
	// else if (e->ftype == 2)
	// {

	// }	//ft_julia();
	// else if (e->ftype == 3)
	// {

	// }	//ft_newtn();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Fract'ol");
	mlx_loop(e->mlx);
}

int main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);

	return(0);
}