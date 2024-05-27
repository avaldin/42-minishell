/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:31:04 by avaldin           #+#    #+#             */
/*   Updated: 2024/05/27 12:01:48 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../HDRS/execution.h"
#include "../HDRS/get_next_line.h"
#include "../include/libft/libft.h"
#include "../HDRS/parsing.h"

static char	*apply_var_heredoc(char *token, char **env, int *i, t_data *args)
{
	char	*var;
	int		len_name;

	len_name = 0;
	if (token[*i + 1] == '?')
		return (str_modify(token, *i, 2, ft_itoa(args->exit_status)));
	while (((token[*i + len_name + 1] < 91 && token[*i + len_name + 1] > 64)
			|| (token[*i + len_name + 1] < 123 && token[*i + len_name + 1] > 96)
			|| (token[*i + len_name + 1] < 58 && token[*i + len_name + 1] > 47))
		&& token[*i + len_name + 1] != '"' && token[*i + len_name + 1] != 39)
		len_name++;
	if (!len_name)
		return ((*i)++, token);
	var = find_var(&token[*i + 1], env, len_name);
	if (!var)
		return (str_cut(token, *i, *i + len_name));
	*i += ft_strlen(var, 0);
	token = str_modify(token, *i - ft_strlen(var, 0), len_name + 1, var);
	return (token);
}

static char	*_pars_heredoc(t_data *args, t_file *file, char *line)
{
	int		i;

	i = 0;
	while (file && !file->heredoc_protec && line[i])
	{
		if (line[i] == '$')
			line = apply_var_heredoc(line, args->env, &i, args);
		else
			i++;
	}
	return (line);
}

char	*_heredoc_prompt(t_data *args, char *line, int pipe_heredoc[2])
{
	line = get_next_line(STDIN_FILENO);
	if (!line)
	{
		free (line);
		close (pipe_heredoc[0]);
		close (pipe_heredoc[1]);
		_exit_failure(args);
	}
	return (line);
}

int	_heredoc_handling(t_data *args, t_file *file)
{
	char	*line;
	int		name_len;
	int		pipe_heredoc[2];

	line = NULL;
	sig_int(2);
	if (pipe(pipe_heredoc) == -1)
		_exit_failure(args);
	name_len = ft_strlen(file->name[1], 0);
	while (42)
	{
		line = _heredoc_prompt(args, line, pipe_heredoc);
		if (file->name && !ft_strncmp(line, file->name[1], name_len)
			&& line[name_len] == '\n')
			break ;
		line = _pars_heredoc(args, file, line);
		if (write(pipe_heredoc[1], line, ft_strlen(line, 0)) == -1)
		{
			close (pipe_heredoc[0]);
			close (pipe_heredoc[1]);
			_exit_failure(args);
		}
		free(line);
	}
	return (free (line), close(pipe_heredoc[1]), pipe_heredoc[0]);
}
