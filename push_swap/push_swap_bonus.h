/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:53 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 16:56:13 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define MERROR 0
# define ERROR 1

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_stk
{
	int				nbr;
	struct s_stk	*prev;
	struct s_stk	*next;
}	t_stk;

typedef struct s_info
{
	char	*str;
	t_stk	*stka;
	t_stk	*stkb;
}	t_info;

void	del_stk(t_stk **stk);
void	cmd_s(t_stk *stka, t_stk *stkb);
void	cmd_p(t_stk **from, t_stk **to, t_stk *p);
void	cmd_r(t_stk **stka, t_stk **stkb, int i);
void	check_sorted(t_info *info);
void	wrong_cmd(t_info *info, char *str);
void	use_cmd(t_info *info, char *str);
void	ft_free(char **arr);
void	reading(t_info *info);
void	check_same(t_stk *stka, t_stk *nstk);
int		check_rnbr(t_stk *stka, char *str);
void	add_to_stack(t_stk **stka, char *av);
int		check_size(char *str, int minus, int i);

#endif