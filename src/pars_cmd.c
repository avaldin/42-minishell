/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:53:12 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/15 12:19:24 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	cmd_process_var(t_section *sect, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (sect->temp && sect->temp[++i])
		if (sect->protection[i] != 2)
		{
			j = 0;
			while (sect->temp && sect->temp[i] && sect->temp[i][j])
			{
				if (sect->temp[i][j] == '$')
				{
					if (!sect->temp[i][j + 1] && sect->protection[i + 1] != 0 && sect->protection[i] == 0)
						sect->temp[i] = str_cut(sect->temp[i], j, j + 1);
					else
						sect->temp[i] = apply_var(sect->temp[i], env, &j);
				}
				else
					j++;
			}
		}
}

void	cmd_temp_fill(t_section *sect)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (sect->pipe[i])
	{
		if (sect->pipe[i] == '"' || sect->pipe[i] == 39)
		{
			if (i != j)
				sect->temp[sect->tmp_len++] = ft_strdup(sect->pipe, j, i - j);
			sect->temp[sect->tmp_len] = ft_calloc(skip_quote(&sect->pipe[i]) + 1, sizeof(char));
			if (!sect->temp)
				exit(44); //pas ok
			sect->protection[sect->tmp_len++] = 2;
			if (sect->pipe[i] == '"')
				sect->protection[sect->tmp_len - 1] = 1;
			i += write_quote(&sect->pipe[i], sect->temp[sect->tmp_len - 1]) + 1;
			j = i + 1;
		}
		i++;
	}
	if (i != j)
		sect->temp[sect->tmp_len++] = ft_strdup(sect->pipe, j, i - j);
}

void	cmd_quote_expender(t_section *sect)
{
	sect->temp = ft_calloc(2 * quote_count(sect->pipe) + 2, sizeof(char *));
	if (!sect->temp)
		exit (20); // pas ok
	sect->protection = ft_calloc(2 * quote_count(sect->pipe) + 2, sizeof(int));
	if (!sect->protection)
		exit(79); //pas ok
	cmd_temp_fill(sect);
}

void	command(t_section *first, char **env)
{
	t_section	*sect;

	sect = first;
	while (sect)
	{
		cmd_quote_expender(sect);
		cmd_process_var(sect, env);
		if (sect->temp)
		{
			cmd_split(sect);
			//cmd_union(sect);
		}
		sect = sect->next;
	}
}