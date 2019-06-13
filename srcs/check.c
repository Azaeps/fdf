/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 13:04:30 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 16:07:06 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*int		check_ss(t_lst *lst, int x, int y, int z)
{
	while (lst->next)
	{
		while (lst->s[x])
		{
			while (lst->s[x] >= '0' && lst->s[x] <= '9')
			{
				if (lst->s[x + 1] < '0' || lst->s[x + 1] > '9')
				{
					z++;
					break ;
				}
				x++;
			}
			x++;
		}
		x = 0;
		printf("%d  %d\n", y, z);
		if (z != y && y != 0)
			return (0);
		y = z;
		z = 0;
		lst = lst->next;
	}
	return (1);
}*/

int		check_lines(t_lst *list, int verif, int i, int nbr)
{
	while (list->next)
	{
		i = 0;
		nbr = 1;
		while (list->s[i])
		{
			if (list->s[i] == ' ' || list->s[i] == '-' || list->s[i] == '+')
			{
				while (list->s[i] == ' ')
					i++;
				if (list->s[i] && list->s[i] != '-' && list->s[i] != '+')
					nbr++;
			}
			else if (list->s[i] < '0' || list->s[i] > '9')
				return (0);
			else
				i++;
		}
		if (verif == 0)
			verif = nbr;
		if (verif != nbr)
			return (0);
		list = list->next;
		dprintf(1, "Int Ligne 1 :%d || Comparaison autre ligne :%d\n", verif, nbr);
	}
	return (1);
}

int		check(t_lst *lst)
{
	if (!(check_lines(lst, 0, 0, 0)))
		return (0);
	return (1);
}
