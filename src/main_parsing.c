/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/15 09:36:56 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_section	*add_section(t_section *first, char *line, int start, int end)
{
	t_section	*sect;

	sect = ft_calloc(1, sizeof(t_section));
	if (!sect)
		return (NULL); // pas ok
	sect->pipe = ft_strdup(line, start, end - start);
	if (!sect->pipe)
		exit(66); //pas ok
	first = ft_sectadd_back(first, sect);
	return (first);
}

t_section	*create_section(char *line)
{
	int			i;
	int			j;
	t_section	*first;

	i = 0;
	j = 0;
	first = NULL;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
			i += skip_quote(&line[i]) + 1;
		else if (line[i] == '|' || !line[i])
		{
			first = add_section(first, line, j, i);
			j = i + 1;
		}
		i++;
	}
	first = add_section(first, line, j, i);
	return (first);
}

t_section *parsing(char *line, char **env)
{
	t_section	*first;

	if (checking(line))
		return (NULL);
	first = create_section(line);
	redirection(first, env);
	command(first, env);
	return (first);
}
