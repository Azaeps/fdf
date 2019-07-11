/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 22:37:46 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 06:57:32 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

int		aff(t_env *env)
{
	int		x;
	int		y;
	int		y1;

	x = INDEX->co_x * 20 + 100;
	y = INDEX->co_y * 20 + 100;
	y1 = y;
	while (INDEX->next)
	{
		y1 = y;
		if (INDEX->num > 0)
		{
			while (x < INDEX->co_x * 20 + 100)
				mlx_pixel_put(env->ptr, env->win, x++,
					INDEX->co_y * 20 + 100, 0xFFFF00);
			while (y < INDEX->co_y * 20 + 100)
				mlx_pixel_put(env->ptr, env->win,
					INDEX->co_x * 20 + 100, y++, 0xFFFF00);
		}
		else if (INDEX->num < 0)
		{
			while (x < INDEX->co_x * 20 + 100)
				mlx_pixel_put(env->ptr, env->win, x++,
					INDEX->co_y * 20 + 100, 0x00CC2C);
			while (y < INDEX->co_y * 20 + 100)
				mlx_pixel_put(env->ptr, env->win,
					INDEX->co_x * 20 + 100, y++, 0x00CC2C);
		}
		else
		{
			while (x < INDEX->co_x * 20 + 100)
				mlx_pixel_put(env->ptr, env->win, x++,
					INDEX->co_y * 20 + 100, 0xFF0000);
			while (y < INDEX->co_y * 20 + 100)
				mlx_pixel_put(env->ptr, env->win,
					INDEX->co_x * 20 + 100, y++, 0xFF0000);
		}
		y = y1;
		x = INDEX->co_x * 20 + 100;
		if (INDEX->next->co_y > INDEX->co_y)
			y = INDEX->co_y * 20 + 100;
		INDEX = INDEX->next;
	}
	return (0);
}
