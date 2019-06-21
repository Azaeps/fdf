/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 22:37:46 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/21 05:30:32 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

int		aff(t_env *env)
{
	int		x;
	int		y;
	int		y1;

	x = INDEX->co_x * 20 + 200;
	y = INDEX->co_y * 20 + 200;
	y1 = y;
	while (INDEX->next)
	{
		y1 = y;
		if (INDEX->num > 0)
		{
			while (x < INDEX->co_x * 20 + 200)
				mlx_pixel_put(env->ptr, env->win, x++, INDEX->co_y * 20 + 200, 0xFFFF00);
			while (y < INDEX->co_y * 20 + 200)
				mlx_pixel_put(env->ptr, env->win, INDEX->co_x * 20 + 200, y++, 0xFFFF00);
		}
		else
		{
			while (x < INDEX->co_x * 20 + 200)
				mlx_pixel_put(env->ptr, env->win, x++, INDEX->co_y * 20 + 200, 0xFF0000);
			while (y < INDEX->co_y * 20 + 200)
				mlx_pixel_put(env->ptr, env->win, INDEX->co_x * 20 + 200, y++, 0xFF0000);
		}
		y = y1;
		x = INDEX->co_x * 20 + 200;
		if (INDEX->next->co_y > INDEX->co_y)
			y = INDEX->co_y * 20 + 200;
		INDEX = INDEX->next;
	}
    return (0);
}