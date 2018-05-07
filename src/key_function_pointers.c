/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_pointers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:08:03 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 16:08:04 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_fp_up(t_m *m, int press)
{
	m->togs->up = press ? 1 : 0;
}

void	key_fp_down(t_m *m, int press)
{
	m->togs->down = press ? 1 : 0;
}

void	key_fp_left(t_m *m, int press)
{
	m->togs->left = press ? 1 : 0;
}

void	key_fp_right(t_m *m, int press)
{
	m->togs->right = press ? 1 : 0;
}
