/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 14:00:53 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 15:56:20 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_env
{
	struct s_fillit	*next;
	void            *ptr;
    void            *win;
    int             co_x;
    int             co_y;
}					t_env;

#endif