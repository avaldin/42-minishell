/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:01:56 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/06 15:37:32 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	red_length(char *line)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	while (line[i] && !(line[i] == ' ' || line[i] == '	' || line[i] == '<' || line[i] == '>'))
	{
		if (line[i] == '"' || line[i] == 39)
		{
			len += skip_quote(&line[i]) + 1;
			i += skip_quote(&line[i]) + 1;
		}
		len++;
		i++;
	}
	return (len);
}


void	extract_red(t_red *red, char *line)
{
	char	*redirect;
	int		red_count;
	int 	i;

	red_count = 1;
	if (line[0] == line[1])
		red_count = 2;
	redirect = ft_calloc(red_length(&line[red_count]) + 1, sizeof(char));
	if (!redirect)
		exit(4); // pas ok
	if (line[0] == '<')
		red->direction = -1 * red_count;
	else
		red->direction = red_count;
	i = red_count;
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	redirect = ft_strdup(line, i, red_length(&line[red_count]));
	red->file[0] = redirect;
}

char	*pars_red(char *line, t_section *sect)
{
	int 	i;
	t_red	*red;
	t_red	*first_red;

	i = 0;
	first_red = NULL;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
			i += skip_quote(&line[i]) + 1;
		else if (line[i] == '<' || line[i] == '>')
		{
			red = ft_calloc(1, sizeof(t_red));
			if (!red)
				return (NULL); // pas ok
			red->file = ft_calloc(3, sizeof(char *));
			if (!red->file)
				return (NULL); // pas ok
			extract_red(red, &line[i]);
			first_red = ft_redadd_back(first_red, red);
		}
		i++;
	}
	sect->first_red = first_red;
	return (line);
}

void	redirection(t_section *first, char **env)
{
	t_section *sect;

	(void)env;

	sect = first;
	while (sect)
	{
		pars_red(sect->pipe, sect);
		sect = sect->next;
	}
}