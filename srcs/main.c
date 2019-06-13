/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 15:52:51 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 14:39:23 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

t_lst	*fill(t_lst *lst, int fd)
{
	int		ret;
	int		x;
	t_lst	*tmp;

	tmp = lst;
	while ((ret = get_next_line(fd, &lst->line)))
	{
		lst->next = (t_lst *)malloc(sizeof(t_lst));
		lst = lst->next;
	}
	lst->next = NULL;
	lst = tmp;
	return (lst);
}

int		main(int ac, char **av)
{
	t_lst	*lst;
	int		fd;
	int		x;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf input_file\n");
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		error();
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst = fill(lst, fd);
	if ((x = check(lst)) == 1)
		printf(":):):):)");
	else
		printf(":(:(:(:(");
}
