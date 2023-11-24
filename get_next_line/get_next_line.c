/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:32:36 by jooh              #+#    #+#             */
/*   Updated: 2023/10/16 13:37:32 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	theleftstr(t_list *p, t_list **info)
{
	char	*str;
	char	*newstr;
	size_t	slen;

	str = p->save_char;
	slen = 0;
	while (str[slen] != '\n')
		slen++;
	slen++;
	str += slen;
	p->len -= slen;
	newstr = malloc(p->len + 1);
	if (newstr == 0)
	{
		free(p->save_char);
		del_lst(p, info);
		return ;
	}
	slen = -1;
	while (++slen < p->len)
		newstr[slen] = str[slen];
	newstr[slen] = 0;
	free(p->save_char);
	p->save_char = newstr;
}

char	*split_by_endl(t_list *p, t_list **info)
{
	char	*str;
	char	*ret_str;
	int		len;
	int		i;

	str = p->save_char;
	len = 0;
	while (str[len] != '\n')
		len++;
	ret_str = malloc(len + 2);
	if (ret_str == 0)
	{
		free(str);
		return (0);
	}
	i = -1;
	while (++i < len + 1)
		ret_str[i] = str[i];
	ret_str[i] = 0;
	theleftstr(p, info);
	return (ret_str);
}

int	check_endl(t_list *p)
{
	size_t	i;

	if (p->save_char == 0)
		return (0);
	i = 0;
	while (i < p->len)
	{
		if (*(p->save_char + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*add_new_back(t_list **info, int fd)
{
	t_list	*newlst;
	t_list	*p;

	newlst = malloc(sizeof(t_list));
	if (newlst == 0)
		return (0);
	newlst->save_char = 0;
	newlst->fdnbr = fd;
	newlst->len = 0;
	newlst->next = 0;
	if (*info == 0)
	{
		*info = newlst;
		return (newlst);
	}
	p = *info;
	while (p->next)
		p = p->next;
	p->next = newlst;
	return (newlst);
}

char	*get_next_line(int fd)
{
	static t_list	*info;
	t_list			*p;
	char			*str;

	if (fd == 2 || fd < 0)
		return (0);
	p = info;
	while (p && p->fdnbr != fd)
		p = p->next;
	if (p == 0)
		p = add_new_back(&info, fd);
	if (p == 0)
		return (0);
	if (check_endl(p))
		str = split_by_endl(p, &info);
	else
		str = mem_and_read(p, &info);
	if (str == 0)
		del_lst(p, &info);
	return (str);
}
