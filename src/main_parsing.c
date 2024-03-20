/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/20 14:21:00 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//enum special_c	special_caracter(char *c)
//{
//	if (*c == '"')
//		return (DOUBLE_QUOTE);
//	if (*c == 39)
//		return (QUOTE);
//	if (*c == '|')
//	{
//		if (c[1] == '|')
//			return (DOUBLE_PIPE);
//		return (PIPE);
//	}
//	if (*c == '>')
//	{
//		if (c[1] == '>')
//			return (DOUBLE_RIGHT_BRACKET);
//		return (RIGHT_BRACKET);
//	}
//	if (*c == '<')
//	{
//		if (c[1] == '<')
//			return (DOUBLE_LEFT_BRACKET);
//		return (LEFT_BRACKET);
//	}
//	return (NONE);
//}
//
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
	return (i);
}
//// quand il y a une quote je passe jusqu'a ce qu'elle se termine psk on a pas a
//// changer ce qu'il y a dedans
//
//
//int	operator_count(char *line)
//{
//	int i;
//	int count;
//
//	i = 0;
//	count = 0;
//	while (line[i])
//	{
//		if (line[i] == '"' || line[i] == 39)
//		{
//			i += quote(&line[i], NULL, NULL);
//		}
//		else if (line[i] == '|')
//			count++;
//		else if (line[i] == '<' || line[i] == '>')
//		{
//			if (line[i] == line[i + 1])
//				i++;
//			count++;
//		}
//		i++;
//	}
//	return (count);
//}
//// je compte les operateurs pour savoir combien d'espace je vais ajouter pour
//// le nouveau malloc de la ligne.
//
//void	create_new_line(char *line, char *new_line)
//{
//	int	i;
//	int	i_nl;
//
//	i = 0;
//	i_nl = 0;
//	while (line[i])
//	{
//		if (line[i] == '"' || line[i] == 39)
//		{
//			new_line[i_nl] = line[i];
//			i += quote(line, new_line, &i_nl);
//			new_line[i_nl++] = line[i++];
//		}
//		else if (special_caracter(&line[i]) > 2)
//		{
//			new_line[i_nl++] = ' ';
//			new_line[i_nl++] = line[i];
//			if (line[i] == line[i + 1])
//				new_line[i_nl++] = line[i++];
//			new_line[i_nl++] = ' ';
//		}
//		else
//			new_line[i_nl++] = line[i++];
//		new_line[i_nl] = 0;
//		printf("%s\n", new_line);
//	}
//	new_line[i_nl] = '\0';
//}
//
//void	add_space(char *line)
//{
//	char	*new_line;
//
//	new_line = (char *)ft_calloc(ft_strlen(line) + 2 * operator_count(line), 1);
//	if (!new_line)
//		return ; 		// error a fix
//	create_new_line(line, new_line);
//	printf("string = %s\n", new_line);
//}
//
// j'ajoute des espaces entres chaques operateurs pour que le split ce passe bien
// car on peut coller les operateurs aux reste comme cmd1|cmd2.
//
//void	parsing(char *line)
//{
//	if (!line || !line[0])
//		return ;
//	add_space(line);
//}



/*
no end quote ok mais double | pas ok, random operateur qui se suivent non plus,
redirection a faire attention entre mauvais fichier et parse error near '...'

 */

void	pars_section(char *line, int len, t_section *first)
{

}

char *str_cut(char *line, int len)
{
	int i;
	char *new_line;

	i = 0;
	new_line = ft_calloc(ft_strlen(line) - len, sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	while (line[i + len + 1])
	{
		new_line[i] = line[i + len + 1];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
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
				i += skip_quote(&line[i]);
			i++;
		}
		//pars_section(line, i, first);     //calloc
		printf("avant = %s\n", line);
		if (!line[i])
		{
			free(line);
			line = NULL;
		}
		else
			line = str_cut(line, i);    //calloc
		printf("apres = %s\n\n\n", line);
	}
	return (first);
}

















