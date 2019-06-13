/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maintest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:46:03 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 11:29:45 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "fdf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     mouse_click(int button, int x, int y, t_env *env)
{
    int     testx;
    int     testy;
    float   m;

    if (button == 1)
    {
        env->co_x = x;
        env->co_y = y;
    }
    if (button == 2)
    {
        testx = env->co_x;
        testy = env->co_y;
        m = ((y - testy)/(x - testx));
        while (testx++ < x)
        {
            testy = (m * testx) + y;
            mlx_pixel_put(env->ptr, env->win, testx, testy, 0xFFFFFF);
        }
/*        if (x > testx && y > testy)
        {
            while (x > testx)
            {
                mlx_pixel_put(env->ptr, env->win, testx++, testy--, 0xFFFFFF);
            }
        }
        else
            while (x < testx)
                mlx_pixel_put(env->ptr, env->win, testx--, testy, 0xFFFFFF);
*/        
    }
    return (0);
}

int     main(void)
{
    t_env   *env;
    int     x;
    int     y;
    int     z;
    int     a;

    x = 200;
    y = 600;
    env->ptr = mlx_init();
    env->win = mlx_new_window(env->ptr, 800, 800, "test");
    while (x < 600)
    {
        mlx_pixel_put(env->ptr, env->win, x++, 200, 0xFFFFFF);
        mlx_pixel_put(env->ptr, env->win, 200, x, 0xFFFFFF);
        mlx_pixel_put(env->ptr, env->win, y--, 600, 0xFFFFFF);
        mlx_pixel_put(env->ptr, env->win, 600, y, 0xFFFFFF);
    }
    mlx_mouse_hook(env->win, &mouse_click, env);
    mlx_loop(env->ptr);
}