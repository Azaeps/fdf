/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 11:35:50 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 07:02:21 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

t_lst	*fill(t_lst *lst, int fd)
{
	int		ret;
	t_lst	*tmp;
	char	*line;

	tmp = lst;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		lst->s = line;
		lst->next = init_lst();
		lst = lst->next;
	}
	return (tmp);
}

int		main(int ac, char **av)
{
	t_lst	*lst;
	int		fd;
	t_env	*env;

	env = init_env();
	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf input_file\n");
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		error();
	lst = init_lst();
	lst = fill(lst, fd);
	env = check(lst, 0, env);
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, 800, 800, "test");
	aff(env);
	mlx_mouse_hook(env->win, test, env);
	mlx_loop(env->ptr);
	free_list(lst);
	free_env(env);
}
