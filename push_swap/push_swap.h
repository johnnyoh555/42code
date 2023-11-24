/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:35:01 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 16:56:05 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MERROR 0
# define ERROR 1

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stk
{
	int				nbr;
	int				flag;
	unsigned int	tnum;
	struct s_stk	*prev;
	struct s_stk	*next;
}	t_stk;

typedef struct s_info
{
	unsigned int	dn;
	unsigned int	size;
	t_stk			*stka;
	t_stk			*stkb;
	t_stk			*stkc;
}	t_info;

void	del_stk(t_stk **stk);
void	sort_by3_a(t_info *info);
void	sort_by3_b(t_info *info);
void	sort_by4_a(t_info *info);
void	sort_by4_b(t_info *info);
void	sort_print(t_info *info);
void	sort_print3_a(t_info *info, unsigned int i, int j);
void	optimize_3a(t_info *info, unsigned int *i, int *j);
void	sort_print3_b(t_info *info, unsigned int i, int j);
void	optimize_3b(t_info *info, unsigned int *i, int *j);
void	optimize_4b(t_info *info, unsigned int *i, int *j);
void	sort_print4_b(t_info *info, unsigned int i, int j);
void	optimize_4a(t_info *info, unsigned int *i, int *j);
void	sort_print4_a(t_info *info, unsigned int i, int j);
void	del_stk(t_stk **stk);
void	stkb_to_stka(t_info *info, int i);
void	cmd_s(t_stk *stka, t_stk *stkb);
void	cmd_p(t_stk **from, t_stk **to, t_stk *p);
void	cmd_r(t_stk **stka, t_stk **stkb, int i);
void	hard_code(t_info *info);
void	push_max5(t_info *info, t_stk *p);
void	push_max4(t_info *info, t_stk *p);
void	smallcase(t_info *info);
void	change_nbr(t_stk *stk, int i);
void	check_sorted(t_info *info);
void	copy_stk(t_stk *stka, t_stk **stkc);
void	copy_to_stkc(t_stk *new, t_stk **stkc);
void	change_by_index(t_info *info);
void	start_sort(t_info *info);
void	extension(t_info *info, int ac);
void	ft_free(char **arr);

#endif