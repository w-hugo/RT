/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:54:58 by aanzieu           #+#    #+#             */
/*   Updated: 2017/06/23 13:22:02 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <gpu_rt.h>
/*
void	add_sphere_tmp(t_sphere **spheres, double radius, t_vec3d pos)
{
	t_sphere *new_sphere;
	t_sphere *tmp;

	tmp = *spheres;
	new_sphere = malloc(sizeof(t_sphere));
	new_sphere->radius = radius;
	new_sphere->pos = pos;
	new_sphere->next = NULL;

	if (!tmp)
		*spheres = new_sphere;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_sphere;
	}
}
*/
t_plane		*new_plan(t_plane *nw, int id)
{
	t_plane	*p;

	if (!(p = (t_plane*)malloc(sizeof(t_plane))))
		ft_putendl_fd("Erroc Malloc on Cone", 1);
	p->id = id;
	p->up = nw->up;
	p->pos = nw->pos;
	p->color = nw->color;
	p->chess = nw->chess;
	p->reflexion_coef = nw->reflexion_coef;
	p->refraxion_coef = nw->refraxion_coef;
	p->next = NULL;
	return (p);
}

t_disk		*new_disk(t_disk *nw, int id)
{
	t_disk	*d;

	if (!(d = (t_disk*)malloc(sizeof(t_disk))))
		ft_putendl_fd("Erroc Malloc on Cone", 1);
	d->id = id;
	d->up = nw->up;
	d->pos = nw->pos;
	d->color = nw->color;
	d->radius = nw->radius;
	d->radius_squared = nw->radius_squared;
	d->reflexion_coef = nw->reflexion_coef;
	d->refraxion_coef = nw->refraxion_coef;
	d->chess = nw->chess;
	d->next = NULL;
	return (d);
}

t_cone		*new_cone(t_cone *nw, int id)
{
	t_cone	*c;

	if (!(c = (t_cone *)ft_memalloc(sizeof(t_cone))))
		ft_putendl_fd("Erroc Malloc on Cone", 1);
	c->id = id;
	c->half_angle = nw->half_angle;
	c->pos = nw->pos;
	c->up = nw->up;
	c->color = nw->color;
	c->reflexion_coef = nw->reflexion_coef;
	c->refraxion_coef = nw->refraxion_coef;
	c->height = nw->height;
	c->min = nw->min;
	c->max = nw->max;
	c->chess = nw->chess;
	c->next = NULL;
	return (c);
}

t_sphere	*new_sphere(t_sphere *nw, int id)
{
	t_sphere	*s;

	if (!(s = (t_sphere *)ft_memalloc(sizeof(t_sphere))))
		ft_putendl_fd("Erroc Malloc on Sphere", 1);
	s->id = id;
	s->radius = nw->radius;
	s->pos = nw->pos;
	s->color = nw->color;
	s->chess = nw->chess;
	s->reflexion_coef = nw->reflexion_coef;
	s->refraxion_coef = nw->refraxion_coef;
	s->next = NULL;
	return (s);
}

t_cylinder	*new_cylinder(t_cylinder *nw, int id)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)ft_memalloc(sizeof(t_cylinder))))
		ft_putendl_fd("Erroc Malloc on Cylinders", 1);
	cy->id = id;
	cy->pos = nw->pos;
	cy->up = nw->up;
	cy->up_v = nw->up_v;
	cy->radius = nw->radius;
	cy->color = nw->color;
	cy->reflexion_coef = nw->reflexion_coef;
	cy->refraxion_coef = nw->refraxion_coef;
	cy->next = NULL;
	cy->chess = nw->chess;
	return (cy);
}

t_light		*new_light(t_light *nw)
{
	t_light	*l;

	if (!(l = (t_light *)ft_memalloc(sizeof(t_light))))
		ft_putendl_fd("Erroc Malloc on Light", 1);
	l->pos = nw->pos;
	l->dir = nw->dir;
	l->dir_v = vector_normalize(vector_calculate(nw->dir, nw->pos));
	l->color = nw->color;
	l->intensity_coef = nw->intensity_coef;
	l->next = NULL;
	return (l);
}
