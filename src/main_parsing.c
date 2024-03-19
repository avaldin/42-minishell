/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/19 12:46:04 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int quote(char *line)
{
	int i;

	i = 0;
	if (line[i++] == '"')
	{
		while (line[i] && line[i] != '"')
			i++;
		if (!line[i])
		{
			printf("no end double quote\n");
			exit(1);                          // erreur a gerer
		}
	}
	else
	{
		while (line[i] && line[i] != 39)  // a test
			i++;
		if (!line[i])
		{
			printf("no end quote\n");
			exit(1);                          // erreur a gerer
		}
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

//void	add_space(char *line)
//{
//	char	*new_line;
//	int		i;
//
//	i = 0;
//	new_line = (char *)ft_calloc(ft_strlen(line) + 2 * operator_count(line), 1);
//}

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
add_space doit ajouter des espaces entre les operateurs et redirections.



 */