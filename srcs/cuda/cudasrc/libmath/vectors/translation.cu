/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 10:49:50 by svilau            #+#    #+#             */
/*   Updated: 2017/03/17 14:07:23 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
		#include <rt.h>
		#include <vectors.h>
		#include <gpu_rt.h>
}

__host__ __device__ void	translate(t_vec3d *point, double x, double y, double z)
{
	point->x += x;
	point->y += y;
	point->z += z;
}

__host__ __device__ void		vector_rot_y(t_vec3d *z, t_vec3d *x, double angle)
{
	t_vec2d		a;
	t_vec2d		b;

	a.x = z->x;
	a.y = z->z;
	b.x = x->x;
	b.y = x->z;
	z->x = a.y * sin(angle) + a.x * cos(angle);
	z->z = a.y * cos(angle) - a.x * sin(angle);
	x->x = b.y * sin(angle) + b.x * cos(angle);
	x->z = b.y * cos(angle) - b.x * sin(angle);
}

__host__ __device__ void		vector_rot_x(t_vec3d *y, t_vec3d *z, double angle)
{
		t_vec2d		a;
		t_vec2d		b;

	a.x = y->y;
	a.y = y->z;
	b.x = z->y;
	b.y = z->z;
	y->y = a.x * cos(angle) - a.y * sin(angle);
	y->z = a.x * sin(angle) + a.y * cos(angle);
	z->y = b.x * cos(angle) - b.y * sin(angle);
	z->z = b.x * sin(angle) + b.y * cos(angle);
}

__host__ __device__ void		vector_rot_z(t_vec3d *x, t_vec3d *y, double angle)
{
	t_vec2d	a;
	t_vec2d		b;

	a.x = x->x;
	a.y = x->y;
	b.x = y->x;
	b.y = y->y;
	x->x = a.y * sin(angle) + a.x * cos(angle);
	x->y = a.y * cos(angle) - a.x * sin(angle);
	y->x = b.y * sin(angle) + b.x * cos(angle);
	y->y = b.y * cos(angle) - b.x * sin(angle);
}