/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:33:31 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:33:32 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_dbl(char **arr, int i)
{
	while (arr[i--])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

int		is_valid_hex(char *s)
{
	if (ft_strlen(s) > 10 || ft_strncmp(s, "0x", 2))
		return (0);
	++s;
	while (*(++s))
		if (!ft_isalnum(*s))
			return (0);
	return (1);
}

void	reset_xyz(t_m *m)
{
	int x;
	int y;
	int	gap;

	gap = (m->x_count > m->y_count ? WIN_WIDTH / (m->x_count - 1) :
		WIN_HEIGHT / (m->y_count - 1)) * BORDER;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			m->grid[y][x].x = m->backup[y][x].x;
			m->grid[y][x].y = m->backup[y][x].y;
			m->grid[y][x].z = m->backup[y][x].z;
			m->grid[y][x].c = m->backup[y][x].c;
			m->grid[y][x].c_lock = m->backup[y][x].c_lock;
		}
	}
	m->mid_x = m->bak_x;
	m->mid_y = m->bak_y;
	m->mid_z = m->bak_z;
	scale_center(m, gap, gap, 10);
	translate_xyz(
		m, (WIN_WIDTH / 2) - m->mid_x, (WIN_HEIGHT / 2) - m->mid_y, 0);
}

/*
** Colour incrementer for gradient generation
*/

int		color_inc(int col_1, int col_2, int level)
{
	int r;
	int g;
	int b;

	if (!level)
		return (col_1);
	r = (((col_1 & R_MASK) - (col_2 & R_MASK)) >> 16) / GRADIENT * level;
	g = (((col_1 & G_MASK) - (col_2 & G_MASK)) >> 8) / GRADIENT * level;
	b = ((col_1 & B_MASK) - (col_2 & B_MASK)) / GRADIENT * level;
	return (((col_1 >> 16) - r) << 16 | (((col_1 & 0xff00) >> 8) - g) << 8 |
		(col_1 & 0xff) - b);
}
