/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:54:00 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/18 13:54:00 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_section	*ft_sectlast(t_section *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_sectadd_back(t_section **lst, t_section *new)
{
	t_section	*t;

	if (*lst && new)
	{
		t = ft_sectlast(*lst);
		t->next = new;
	}
	else if (!*lst)
		*lst = new;
}

t_red	*ft_redlast(t_red *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_redadd_back(t_red **lst, t_red *new)
{
	t_red	*t;

	if (*lst && new)
	{
		t = ft_redlast(*lst);
		t->next = new;
	}
	else if (!*lst)
		*lst = new;
}