/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/22 12:45:13 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"


//void	cleaning_cmd(t_section new_sect, char *line)
//{
//
//}

void	pars_section(char *line, t_section *first)
{
	t_section	*new_sect;
	int			i;

	(void)first;
	i = 0;
	new_sect = ft_calloc(1, sizeof(t_section));
	if (!new_sect)
		return ;  // pas ok
	while (line[i] && line[i] != '|')
	{
		if (line[i] == '"' || line[i] == 39)
			i += skip_quote(&line[i]) + 2;
		else if (line[i] == '<' || line[i] == '>')
		{

			line = str_cut(line, i, i + redirect(new_sect, &line[i]));
			i = 0;
		}
		else
			i++;
		if (!ft_strlen(line))
		{
			printf("NULL\n");
			line = NULL;
		}
	}
	//cleaning_cmd(new_sect, line);
	//ft_lstadd_back(&first, new_sect);
}



t_section *parsing(char *line)
{
	t_section *first;
	int i;

	first = NULL;
	while (line)
	{
		pars_section(line, first);     //calloc
		printf("apres pars section : %s\n", line);
		i = 0;
		while (line && line[i] != '|')
		{
			if (!line[i])
			{
				free(line);
				line = NULL;
			}
			else
				i++;
		}
		if (line)
			line = str_cut(line, 0, i);
		printf("apres cut pipe  : %s\n", line);
	}
	return (first);
}
