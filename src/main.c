/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:16 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/16 16:24:01 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*line;

	(void)argv;
	(void)argc;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	sig_int();
	sig_quit();
	while (42)
	{
		line = readline("str >> ");
		if (!line)
		{
			rl_clear_history();
			free(data->sa);
			free(data);
			exit(12); // pas ok
		}
		add_history(line);
		parsing(line, env, data);
		ft_sectclear(data->first);
	}
	free(data);
	return (0);
}
