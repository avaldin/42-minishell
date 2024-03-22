/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:01:56 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/22 11:28:05 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"



//int red_count(char *line)
//{
//
//}

int	red_length(char *line)
{
	int len;
	int i;

	len = 0;
	i = 0;
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

int	red_fill(char *line, char *redirect)
{
	int i;
	int i_red;

	i_red = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	while (line[i] && !(line[i] == ' ' || line[i] == '	' || line[i] == '<' || line[i] =='>'))
	{
		if (line[i] == '"' || line[i] == 39)
		{
			i_red += write_quote(line, redirect);
			i += skip_quote(&line[i]) + 1;
		}
		else
			redirect[i_red++] = line[i];
		i++;
	}
	redirect[i] = '\0';
	return (i);
}

int redirect(t_section *new_sect, char *line)
{
	char	*redirect;
	int		red_count;
	int		i;

	red_count = 1;
	if (line[0] == line[1])
		red_count = 2;
	redirect = ft_calloc(red_length(&line[red_count]) + 1, sizeof(char));
	if (!redirect)
		exit(4); // pas ok
	if (line[0] == '<')
		new_sect->dir = 1 * red_count;
	else
		new_sect->dir = 10 * red_count;
	i = red_fill(&line[1], redirect);
	printf("redirect = : %s\n", redirect);
	new_sect->redirect = redirect;
	return(i);
}