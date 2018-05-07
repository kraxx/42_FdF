/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:59:40 by jchow             #+#    #+#             */
/*   Updated: 2017/07/25 20:00:03 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_m	m;

	ft_bzero(&m, sizeof(t_m));
	if (ac != 2 || !init_input(&m, av[1]))
		return (write_error());
	write_legend();
	if (m.x_count && m.y_count)
	{
		m.mlx = mlx_init();
		m.win = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, av[1]);
		m.img = (t_img*)ft_memalloc(sizeof(t_img));
		set_hooks(&m);
		mlx_loop(m.mlx);
	}
	return (0);
}
