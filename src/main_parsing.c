/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/06 14:55:52 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//char *cheaking(char *line, char **env)
//{
//	char	*new_line;
//	int 	i;
//
//	i = 0;
//	// cheaking des guillemet , pipe, chevron
//	new_line = pars_var(line, env);
//
//	return (new_line);
//}

//char	*pars_section(char *line, t_section **first)
//{
//	t_section	*new_sect;
//
//	new_sect = ft_calloc(1, sizeof(t_section));
//	if (!new_sect)
//		return (NULL);  // pas ok
//	line = pars_red(line, new_sect);
//	cleaning_cmd(new_sect, line);
//	*first = ft_sectadd_back(*first, new_sect);
//	return (line);
//}

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
//	int			i;
//	int 		j;

	(void)env;
//	i = 0;
//	j = 0;
//	if (cheaking(line, env))
//		return (NULL);
	first = create_section(line);
	redirection(first, env);
	return (first);
}
