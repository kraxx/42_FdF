/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_pointers2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:08:32 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:08:33 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_fp_fn(t_m *m, int press)
{
	m->togs->fn = press ? 1 : 0;
}

void	key_fp_bk_del(t_m *m, int press)
{
	m->togs->bk_del = press ? 1 : 0;
}

void	key_fp_home(t_m *m, int press)
{
	m->togs->home = press ? 1 : 0;
}

void	key_fp_end(t_m *m, int press)
{
	m->togs->end = press ? 1 : 0;
}

void	key_fp_pg_up(t_m *m, int press)
{
	m->togs->pg_up = press ? 1 : 0;
}
