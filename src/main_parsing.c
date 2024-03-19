/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/19 14:00:39 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

enum special_c	special_caracter(char *c)
{
	if (*c == '"')
		return (DOUBLE_QUOTE);
	if (*c == 39)
		return (QUOTE);
	if (*c == '|')
	{
		if (c[1] == '|')
			return (DOUBLE_PIPE);
		return (PIPE);
	}
	if (*c == '>')
	{
		if (c[1] == '>')
			return (DOUBLE_RIGHT_BRACKET);
		return (RIGHT_BRACKET);
	}
	if (*c == '<')
	{
		if (c[1] == '<')
			return (DOUBLE_LEFT_BRACKET);
		return (LEFT_BRACKET);
	}
	return (NONE);
}

int quote(char *line, char *new_line)
{
	int i;

	i = 0;
	if (line[i++] == '"')
		while (line[i] && line[i] != '"')
		{
			if ()
			i++;
		}
	else
		while (line[i] && line[i] != 39)  // a test
		{
			i++;
		}
	if (!line[i])
	{
		printf("no end quote\n");
		exit(1);                          // erreur a gerer
	}
	return (i);
}
// quand il y a une quote je passe jusqu'a ce qu'elle se termine psk on a pas a
// changer ce qu'il y a dedans


int	operator_count(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
		{
			i += quote(&line[i]);
		}
		else if (line[i] == '|')
			count++;
		else if (line[i] == '<' || line[i] == '>')
		{
			if (line[i] == line[i + 1])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}
// je compte les operateurs pour savoir combien d'espace je vais ajouter pour
// le nouveau malloc de la ligne.

void	add_space(char *line)
{
	char	*new_line;
	int		i;
	int		i_nl;

	i_nl = 0;
	i = 0;
	new_line = (char *)ft_calloc(ft_strlen(line) + 2 * operator_count(line), 1);
	if (!new_line)
		return ; 		// error a fix
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
		{
			i += quote(&line[i]);
		}
		else if (line[i] == '|')
			count++;
		else if (line[i] == '<' || line[i] == '>')
		{
			if (line[i] == line[i + 1])
				i++;
			count++;
		}
		i++;
	}
}

// j'ajoute des espaces entres chaques operateurs pour que le split ce passe bien
// car on peut coller les operateurs aux reste comme cmd1|cmd2.

void	parsing(char *line)
{
	if (!line || !line[0])
		return ;
	//add_space(line);
	printf("nb operateur = %d\n line = %s", operator_count(line), line);
}



/*
no end quote ok mais double | pas ok, random operateur qui se suivent non plus,
redirection a faire attention entre mauvais fichier et parse error near '...'

 */