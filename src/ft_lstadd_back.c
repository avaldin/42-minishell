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

void	ft_lstadd_back(t_section **lst, t_section *new)
{
	t_section	*t;

	if (*lst && new)
	{
		t = ft_lstlast(*lst);
		t->next = new;
	}
	else if (!*lst)
		*lst = new;
}
