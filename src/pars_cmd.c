/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:53:12 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/15 10:55:15 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	cmd_quote_expender(t_section *sect)
{
	sect->temp = ft_calloc(2 * quote_count(sect->pipe) + 2, sizeof(char *));
	if (!sect->temp)
		exit (20) // pas ok

}

void	command(t_section *first, char **env)
{
	t_section	*sect;
	char

	sect = first;
	while (sect)
	{
		cmd_quote_expender(sect);
		//cmd_process_var(sect, env);
		//split espace chaque temp[i] sauf protec
		//cmd_union(sect);
		sect = sect->next;
	}
}