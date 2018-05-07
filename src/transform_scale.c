/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:35:34 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 23:44:25 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_custom(t_m *m, int i, int j, int zoom)
{
	int x;
	int y;

	x = -1;
	while (++x < m->x_count)
	{
		y = -1;
		while (++y < m->y_count)
		{
			if (zoom != 0)
			{
				m->grid[y][x].x = i + ((ZOOM_IN) * (m->grid[y][x].x - i));
				m->grid[y][x].y = j + ((ZOOM_IN) * (m->grid[y][x].y - j));
			}
			else
			{
				m->grid[y][x].x = i + ((ZOOM_OUT) * (m->grid[y][x].x - i));
				m->grid[y][x].y = j + ((ZOOM_OUT) * (m->grid[y][x].y - j));
			}
			m->mid_x += i - m->mid_x;
			m->mid_y += j - m->mid_y;
		}
	}
	m->togs->draw_toggle = 1;
}

void	scale_center(t_m *m, double i, double j, double k)
{
	int	x;
	int	y;

	x = -1;
	while (++x < m->x_count)
	{
		y = -1;
		while (++y < m->y_count)
		{
			if (i > 0)
				m->grid[y][x].x = m->mid_x + (i * (m->grid[y][x].x - m->mid_x));
			if (j > 0)
				m->grid[y][x].y = m->mid_y + (j * (m->grid[y][x].y - m->mid_y));
			if (k > 0)
				m->grid[y][x].z *= k;
		}
	}
	m->togs->draw_toggle = 1;
}
