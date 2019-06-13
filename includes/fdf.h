/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 14:00:53 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 14:17:32 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_lst
{
	struct s_lst	*next;
    char            *line;
}					t_lst;

typedef struct      s_env
{
    struct s_env   *next;
    void            *ptr;
    void            *win;
    int             co_x;
    int             co_y;
}                   t_env;

int                 check(t_lst *lst);

#endif