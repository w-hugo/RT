/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mobius.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:48:49 by aanzieu           #+#    #+#             */
/*   Updated: 2017/09/18 16:49:39 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"
#include "../cuda/cudaheader/gpu_rt.h"

void						init_mobius_add(t_mobius *m)
{
	m->id = 0;
	m->radius = 0.2;
	m->pos = new_vector(0, 0, -0.5);
	m->color = (t_color)
	{color_to_coef(236), color_to_coef(205), color_to_coef(162)};
	m->chess = (t_color){-1, -1, -1};
	m->reflection_coef = 0;
	m->refraction_coef = 0;
	m->transparence_coef = 0;
	m->perlin.is_set = 0;
	m->perlin.pre_set = 0;
	m->perlin.scale = 0;
	m->perlin.amount = 0;
	m->next = NULL;
}

static unsigned int			count_mobius(t_mobius *mobius)
{
	t_mobius		*s;
	unsigned int	size;

	size = 0;
	s = mobius;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

void						load_mobius(t_mobius **mobius, t_mobius *mobius_tmp,
							int *mobius_len)
{
	unsigned int	i;
	t_mobius		*tmp;

	if (*mobius != NULL)
	{
		free(*mobius);
		*mobius = NULL;
		*mobius_len = 0;
	}
	i = 0;
	if ((*mobius_len = count_mobius(mobius_tmp)) == 0)
		return ;
	if (!(*mobius = (t_mobius*)malloc(sizeof(t_mobius) * *mobius_len)))
		show_error("Don't Malloc\n");
	tmp = mobius_tmp;
	while (tmp)
	{
		(*mobius)[i] = *tmp;
		tmp = tmp->next;
		i++;
	}
}
