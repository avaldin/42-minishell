/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:20:59 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/08 13:56:24 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_var(char *name, char **env, int len)
{
	int	i;

	i = 0;
	while (ft_strncmp(name, env[i], len))
		i++;
	if (!env[i] || !env[i][len + 1])
		return (NULL);
	return (ft_strdup(name, len + 1, -1));
}

char	*apply_var(char *token, char **env, int *i)
{
	char	*var;
	int 	len_name;

	len_name = 0;
	while ((token[*i + len_name + 1] < 91 && token[*i + len_name + 1] > 64) || (token[*i + len_name + 1] < 123 && token[*i + len_name + 1] > 96) || (token[*i + len_name + 1] < 58 && token[*i + len_name + 1] > 47))
		len_name++;
	if (!len_name)
		return ((*i)++, token);
	var = find_var(&token[*i], env, len_name);
	if (!var)
		return (str_cut(token, *i, *i + len_name));
	*i += ft_strlen(var);
	str_modify(token, *i - ft_strlen(var), len_name + 1, var);
	return (token);
}

void	check_var(t_red *red, char **env, int i)
{
	int		j;

	j = 0;
	while (red->temp[i][j])
	{
		if (red->temp[i][j] == '$')
		{
			if (!red->temp[i][j + 1] && red->protection[i + 1] != 0 && red->protection[i] == 0)
				return ;
			red->temp[i] = apply_var(red->temp[i], env, &j);
		}
		else
			j++;
	}
}

void	process_var(t_section *first, char **env)
{
	t_section	*sect;
	t_red		*red;
	int 		i;

	sect = first;
	while(sect)
	{
		red = sect->first_red;
		while (red)
		{
			i = 0;
			while (red->temp[i])
				if (red->protection[i] != 2)
					check_var(red, env, i++);
			red = red->next;
		}
		sect = sect->next;
	}
}