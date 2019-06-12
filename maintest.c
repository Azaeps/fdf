/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maintest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:46:03 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 15:57:43 by thperchi    ###    #+. /#+    ###.fr     */
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
    if (button == 1)
    {
        env->co_x = x;
        env->co_y = y;
    }
    if (button == 2)
    {
        if (x > env->co_x && y > env->co_y)
        {
            testx = x - env->co_x;
            testy = y - env->co_y;
            ft_putnbr(testx);
            ft_putchar(' ');
            ft_putnbr(testy);
            while (x > env->co_x)
            {
                mlx_pixel_put(env->ptr, env->win, env->co_x++, env->co_y--, 0xFFFFFF);
            }
        }
        else
            while (x < env->co_x)
                mlx_pixel_put(env->ptr, env->win, env->co_x--, env->co_y, 0xFFFFFF);
        
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