/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:46:30 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/16 16:43:15 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_redclear(t_red *lst)
{
	if (lst)
	{
		ft_redclear(lst->next);
		free(lst->file);
		free(lst);
		lst = NULL;
	}
}

void	cmd_clear(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	ft_sectclear(t_section *lst)
{
	if (lst)
	{
		if (lst->next)
			ft_sectclear(lst->next);
		ft_redclear(lst->first_red);
		cmd_clear(lst->cmd);
		free(lst);
		lst = NULL;
	}
}

void	clean_exit(t_data *data)
{
	(void)data;
	exit(66);
}