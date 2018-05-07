/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:55:25 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:55:26 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal(t_m *m, t_coor coor, int y, int x)
{
	coor.x2 = m->grid[y][x + 1].x;
	coor.y2 = m->grid[y][x + 1].y;
	coor.z2 = m->grid[y][x + 1].z;
	coor.c2 = m->grid[y][x + 1].c;
	coor.c_lock = (m->grid[y][x].c_lock &&
		m->grid[y][x + 1].c_lock) ? 1 : 0;
	cohen_sutherland(m->img, coor);
}

static void	draw_vertical(t_m *m, t_coor coor, int y, int x)
{
	coor.x2 = m->grid[y + 1][x].x;
	coor.y2 = m->grid[y + 1][x].y;
	coor.z2 = m->grid[y + 1][x].z;
	coor.c2 = m->grid[y + 1][x].c;
	coor.c_lock = (m->grid[y][x].c_lock &&
		m->grid[y + 1][x].c_lock) ? 1 : 0;
	cohen_sutherland(m->img, coor);
}

static void	draw_lines(t_m *m, int y, int y_lim)
{
	t_coor	coor;
	int		x;

	while (y < y_lim)
	{
		x = -1;
		while (++x < m->x_count)
		{
			coor.x1 = m->grid[y][x].x;
			coor.y1 = m->grid[y][x].y;
			coor.z1 = m->grid[y][x].z;
			coor.c1 = m->grid[y][x].c;
			if (x < m->x_count - 1)
				draw_horizontal(m, coor, y, x);
			if (y < (y_lim == m->y_count ? m->y_count - 1 : y_lim))
				draw_vertical(m, coor, y, x);
		}
		++y;
	}
}

static void	*threader(void *v)
{
	t_view	*view;

	view = (t_view*)v;
	draw_lines(view->m, view->y, view->y_lim);
	return ((void*)view);
}

void		start_draw(t_m *m)
{
	pthread_t	thread[THREAD_COUNT];
	t_view		v[THREAD_COUNT];
	int			y_lim;
	int			i;

	mlx_clear_window(m->mlx, m->win);
	m->img->ptr = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img->data = (int*)mlx_get_data_addr(
		m->img->ptr, &m->img->bpp, &m->img->size, &m->img->e);
	y_lim = m->y_count / THREAD_COUNT;
	i = -1;
	while (++i < THREAD_COUNT)
	{
		v[i].m = m;
		v[i].y = y_lim * i;
		v[i].y_lim = (i == THREAD_COUNT - 1) ? m->y_count : v[i].y + y_lim;
		pthread_create(&thread[i], NULL, threader, &v[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, 0, 0);
	mlx_destroy_image(m->mlx, m->img->ptr);
}
