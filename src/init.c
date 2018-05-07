/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:18:44 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 16:18:44 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	build_grid(t_m *m)
{
	int i;

	if (!(m->grid = (t_xyz **)ft_memalloc(sizeof(t_xyz *) * m->y_count)) ||
		!(m->backup = (t_xyz **)ft_memalloc(sizeof(t_xyz *) * m->y_count)))
		return (0);
	i = -1;
	while (++i < m->y_count)
		if (!(m->grid[i] = (t_xyz *)ft_memalloc(sizeof(t_xyz) * m->x_count)) ||
			!(m->backup[i] = (t_xyz *)ft_memalloc(sizeof(t_xyz) * m->x_count)))
			return (0);
	return (init_env(m) ? 1 : 0);
}

static int	add_node(t_m *m, char **line)
{
	t_line	*node;
	t_line	*ptr;
	int		i;

	i = -1;
	if (!(node = (t_line *)ft_memalloc(sizeof(t_line))))
		return (0);
	node->next = NULL;
	if (!(node->info = (char **)ft_memalloc(sizeof(char *) * m->x_count)))
		return (0);
	while (line[++i])
		if (!(node->info[i] = ft_strdup(line[i])))
			return (0);
	if (!m->line)
		m->line = node;
	else
	{
		ptr = m->line;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
	return (1);
}

static int	parse_data(t_m *m, char *buf)
{
	char **line;

	if (!(line = ft_strsplit(buf, ' ')))
		return (0);
	if (!m->x_count)
		m->x_count = (double)ft_arrsize((void**)line);
	++m->y_count;
	if (ft_arrsize((void**)line) != m->x_count || !add_node(m, line))
		return (0);
	free_dbl(line, m->x_count);
	return (1);
}

int			init_input(t_m *m, char *arg)
{
	char	*buf;
	int		fd;
	int		status;

	if ((fd = open(arg, O_RDONLY)) > 0)
	{
		while ((status = ft_get_next_line(fd, &buf)) == 1)
			if (!parse_data(m, buf))
				return (0);
	}
	else
		return (0);
	close(fd);
	if (status == -1)
		return (0);
	m->togs = (t_togs*)ft_memalloc(sizeof(t_togs));
	m->togs->pulse_toggle = 1;
	return (build_grid(m) ? 1 : 0);
}
