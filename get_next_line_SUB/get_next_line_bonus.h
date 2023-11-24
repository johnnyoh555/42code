/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:31:06 by jooh              #+#    #+#             */
/*   Updated: 2023/10/16 14:06:16 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# elif BUFFER_SIZE < 1
#  error "Right BUFFER SIZE PLZ"
# endif

typedef struct s_list
{
	int				fdnbr;
	char			*save_char;
	size_t			len;
	size_t			mul;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*add_new_back(t_list **info, int fd);
int		check_endl(t_list *p);
char	*split_by_endl(t_list *p, t_list **info);
void	theleftstr(t_list *p, t_list **info);
char	*mem_and_read(t_list *p, t_list **info);
char	*ft_realloc(t_list *p, t_list **info);
void	del_lst(t_list *p, t_list **info);
char	*check_whatread(t_list *p, t_list **info, int n);
char	*read_over(t_list *p, t_list **info);

#endif