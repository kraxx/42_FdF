/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:39:55 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:39:56 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_xyz(t_m *m, double i, double j, double k)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			m->grid[y][x].x += i;
			m->grid[y][x].y += j;
			m->grid[y][x].z += k;
		}
	}
	m->mid_x += i;
	m->mid_y += j;
	m->mid_z += k;
	m->togs->draw_toggle = 1;
}
