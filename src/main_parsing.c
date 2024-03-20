/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/20 16:02:30 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int skip_quote(char *line)
{
	int i;

	i = 0;
	if (line[i++] == '"')
		while (line[i] && line[i] != '"')
			i++;
	else
		while (line[i] && line[i] != 39)  // a test
			i++;
	if (!line[i])
	{
		printf("no end quote\n");
		exit(1);                          // erreur a gerer
	}
	return (i - 1);
}

void write_quote(char *line, char *dest)
{
	int i;

	i = 0;
	if (line[i++] == '"')
		while (line[i] && line[i] != '"')
		{
			dest[i -1] = line[i];
			i++;
		}
	else
		while (line[i] && line[i] != 39)  // a test
		{
			dest[i -1] = line[i];
			i++;
		}
}

int	red_length(char *line)
{
	int len;
	int i;

	len = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	while (line[i] && !(line[i] == ' ' || line[i] == '	'))
	{
		if (line[i] == '"' || line[i] == 39)
		{
			len += skip_quote(&line[i]);
			i += skip_quote(&line[i]) + 1;
		}
		else
			len++;
		i++;
	}
	return (len);
}

void	red_fill(char *line, char *redirect)
{
	int i;

	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	while (line[i] && !(line[i] == ' ' || line[i] == '	'))
	{
		if (line[i] == '"' || line[i] == 39)
		{
			write_quote(line, redirect);
			i += skip_quote(&line[i]) + 1;
		}
		i++;
	}
	redirect[i] = '\0';
}

char *str_cut(char *line, int start, int end)
{
	int i;
	char *new_line;

	i = 0;
	new_line = ft_calloc(ft_strlen(line) - end + start + 1, sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	while (i < start)
	{
		new_line[i] = line[start + i];
		i++;
	}
	i = 0;
	while (line[end + i] && line[end + i + 1])
	{
		new_line[start + i] = line[end + i + 1];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

char *redirect(t_section *new_sect, char *line)
{
	char	*redirect;
	int		red_count;
	int		i;

	(void)new_sect;
	i = 0;
	red_count = 1;
	if (line[i] == line[i + 1])
		red_count = 2;
	redirect = ft_calloc(red_length(&line[red_count]) + 2, sizeof(char));
	if (!redirect)
		return (NULL); // pas ok
	if (line[i] == '<')
		redirect[0] = 1 * red_count;
	else
		redirect[0] = 10 * red_count;
	red_fill(&line[1], redirect);
	line = str_cut(line, 0, red_length(&line[red_count]) + 2);
	return(line);
}

//void	cleaning_cmd(t_section new_sect, char *line)
//{
//
//}

void	pars_section(char *line, int len, t_section *first)
{
	t_section	*new_sect;
	int			i;
	(void)len;
	(void)first;
	i = 0;
	new_sect = ft_calloc(1, sizeof(t_section));
	if (!new_sect)
		return ;  // pas ok
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
			i += skip_quote(&line[i]) + 2;
		else if (line[i] == '<' || line[i] == '>')
		{
			line = redirect(new_sect, &line[i]);
			i = 0;
		}
		else
			i++;
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
		i = 0;
		while (line[i] && line[i] != '|')
		{
			if (line[i] == '"' || line [i] == 39)
				i += skip_quote(&line[i]) + 1;
			i++;
		}
		printf("avant %s\n", line);
		pars_section(line, i, first);     //calloc
		if (!line || !line[i])
		{
			//free(line);
			line = NULL;
		}
		else
			line = str_cut(line, 0, i);    //calloc
		printf("apres %s\n", line);
	}
	return (first);
}

















