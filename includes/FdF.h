/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FdF.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 13:35:57 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 02:27:11 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "./minilibx_macOS/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define INDEX env->index

typedef struct      s_lst
{
	struct s_lst    *next;
	char            *s;
}                    t_lst;

typedef struct      s_index
{
	int             num;
	int             co_x;
	int             co_y;
	struct s_index  *next;
}                   t_index;

typedef struct      s_env
{
	t_index			*index;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				tmp;
	int				yy;
	void            *ptr;
	void            *win;
}                   t_env;


t_env				*check(t_lst *list, int verif, t_env *env);
t_lst				*free_list(t_lst *list);
t_env				*free_env(t_env *env);
t_index				*free_index(t_index	*index);
t_index				*init_index(void);
t_env				*init_env(void);
t_lst				*init_lst(void);
void 				error(void);
int     			aff(t_env *env);
int					test(int button, int x, int y, t_env *env);

#endif