/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:00:55 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/08 10:54:58 by avaldin          ###   ########.fr       */
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
	return (i - 1);
}

int write_quote(char *line, char *dest)
{
	int i;

	i = 0;
	if (line[i++] == '"')
		while (line[i] && line[i] != '"')
		{
			dest[i - 1] = line[i];
			i++;
		}
	else
		while (line[i] && line[i] != 39)  // a test
		{
			dest[i - 1] = line[i];
			i++;
		}
	return (i - 1);

}

char *str_cut(char *line, int start, int end)
{
	int i;
	char *new_line;

	i = 0;
	if (ft_strlen(line) - end + start == 0)
		return (free(line), NULL);
	new_line = ft_calloc(ft_strlen(line) - end + start + 1, sizeof(char));
	if (!new_line)
		exit(3); //pas ok
	while (i < start)
	{
		new_line[i] = line[i];
		i++;
	}
	i = 0;
	while (line[end + i] && line[end + i + 1])
	{
		new_line[start + i] = line[end + i + 1];
		i++;
	}
	new_line[start + i] = '\0';
	free(line);
	return (new_line);
}

//char	*find_var(char *name, char **env)
//{
//	int 	i;
//	int 	j;
//	int 	len;
//	char	*var;
//
//	i = 0;
//	j = 0;
//	len = 0;
//	while ((name[len] < 91 && name[len] > 64) || (name[len] < 123 && name[len] > 96) || (name[len] < 58 && name[len] > 47))
//		len++;
//	while (env[i] && ft_strncmp(name, env[i], ft_strlen(name)))
//		i++;
//	if (!env[i])
//		return (NULL);
//	while (env[i][j] && env[i][j] != '=')
//		j++;
//	return (&env[i][j + 1]);
//}

char	*str_modify(char *str, int i, int len, char *add)  //prend une string, supprime ce qu'il y a a l'indice m sur une taille len, et ajoute la string add a l,indice i
{
	char	*new_str;
	int 	j;
	int 	k;

	if (!str)
		return (NULL);
	new_str = ft_calloc(ft_strlen(str) - len + ft_strlen(add) + 1, sizeof(char));
	if (!new_str)
		exit (24);   //pas ok
	j = -1;
	k = -1;
	while (++j < i)
		new_str[j] = str[j];
	while (add && add[++k])
		new_str[j + k] = add[k];
	j--;
	while (str[len + ++j])
		new_str[j + k] = str[j + len];
	new_str[j + k] = '\0';
	free(str);
	free(add);
	return (new_str);
}

