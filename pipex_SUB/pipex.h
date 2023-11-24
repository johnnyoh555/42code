/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:19:04 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 16:30:23 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_info
{
	char	**path;
	int		idx;
	int		size;
	char	**envp;
	char	**av;
	int		*fd;
	int		hd;
	char	*flagfile;
	pid_t	pid;
}	t_info;

// utils.c
void	ft_dup2(t_info *info, int in, int out);
void	freecmd(char **cmd);
int		quote_process(char *s);

// main.c
int		wait_dl(t_info *info);
void	init_info(t_info *info, int ac, char *av[], char *envp[]);
void	find_path(t_info *info);

// childs.c
void	child(t_info *info);
void	other_childs(t_info *info);
void	last_child(t_info *info);
void	first_child(t_info *info);

// pipes.c
void	im_mario(t_info *info);
void	close_pipe(t_info *info);
char	*str_cpy(t_info *info, char *s, int j, char *c);
char	*ft_slashbs(t_info *info, char *str);

// path_cmd.c
char	*cmd_path(t_info *info, char **cmd, int i);
char	**clean_up_cmd(t_info *info, char *s);

// here_doc.c
void	ctl_error(t_info *info, int i, int j, char *str);
void	make_hdfile(t_info *info);
void	checkfilename(t_info *info);
void	end_seq(t_info *info);

#endif