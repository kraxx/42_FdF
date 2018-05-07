/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:20:09 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 16:20:09 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_c(t_m *m)
{
	int grad;
	int level;
	int x;
	int y;

	grad = ((int)(m->z_max - m->z_min) / (GRADIENT)) > 1 ?
		((int)(m->z_max - m->z_min) / (GRADIENT)) : 1;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			if (!m->backup[y][x].c_lock)
			{
				level = ((m->backup[y][x].z - (int)m->z_min) / grad);
				if (m->backup[y][x].z == m->z_max || level > GRADIENT)
					level = GRADIENT;
				m->backup[y][x].c = (color_inc(COLOR_1, COLOR_2, level));
			}
		}
	}
}

static int	init_z(t_m *m, char **info, int x, int y)
{
	char **tmp;

	if (ft_strchr(info[x], ','))
	{
		if (!(tmp = ft_strsplit(info[x], ',')))
			return (0);
		if (tmp[2] || !ft_atoi_strict(tmp[0]) || !is_valid_hex(tmp[1]))
			return (0);
		m->backup[y][x].z = ft_atoi(tmp[0]);
		m->backup[y][x].c = ft_atoull_base(tmp[1] + 2, 16);
		m->backup[y][x].c_lock = 1;
		free_dbl(tmp, 2);
	}
	else
	{
		if (!ft_atoi_strict(info[x]))
			return (0);
		m->backup[y][x].z = ft_atoi(info[x]);
	}
	return (1);
}

static int	final_touches(t_m *m)
{
	m->bak_x = (m->x_count - 1) / 2.0;
	m->bak_y = (m->y_count - 1) / 2.0;
	m->bak_z = (m->z_min + m->z_max) / 2.0;
	init_c(m);
	reset_xyz(m);
	return (1);
}

static int	set_backup(t_m *m, int x, int y)
{
	m->backup[y][x].x = x;
	m->backup[y][x].y = y;
	if (!init_z(m, m->line->info, x, y))
		return (0);
	m->z_min = m->z_min < m->backup[y][x].z ? m->z_min : m->backup[y][x].z;
	m->z_max = m->z_max > m->backup[y][x].z ? m->z_max : m->backup[y][x].z;
	return (1);
}

int			init_env(t_m *m)
{
	t_line	*node;
	int		x;
	int		y;

	m->z_min = ~0u;
	m->z_max = -999999999.0;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
			if (!set_backup(m, x, y))
				return (0);
		node = m->line->next;
		free_dbl(m->line->info, m->x_count);
		free(m->line);
		m->line = node;
	}
	return (final_touches(m));
}
