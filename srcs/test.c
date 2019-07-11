/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 01:25:25 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 07:03:08 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

int		test(int button, int x, int y, t_env *env)
{
	float dx;
	float dy;
	float m;
	float a;

	if (button == 1)
	{
		env->x1 = x;
		env->y1 = y;
	}
	if (button == 2)
	{
		env->x2 = x;
		env->y2 = y;
		dx = abs(env->x2 - env->x1);
		dy = abs(env->y2 - env->y1);
		m = dy / dx;
		env->tmp = env->x1;
		while (env->tmp++ < env->x2)
		{
			a = m * (env->tmp - env->x1) + env->y1 + 0.5;
			mlx_pixel_put(env->ptr, env->win, env->tmp, a, 0xFFFF00);
		}
	}
	return (0);
}
