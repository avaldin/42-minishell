/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:16 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/06 15:31:44 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_pars(t_section *first)
{
	t_section	*sect;
	t_red		*red;
	int 		i = 1;
	int 		j;
//	int 		k;

	sect = first;
	while (sect)
	{
		printf("\n           section %d\n\n", i);
		j = 1;
//		k = 0;
		red = sect->first_red;
//		printf("\ncmd = ");
//		while (sect->cmd[k])
//		{
//			printf("arg %d = %s;    ", k, sect->cmd[k]);
//			k++;
//		}
		printf("\n");
		while (red)
		{
			printf("\nredirection %d\n\nred name = %s\ndirection = %d\n", j, red->file[0], red->direction);
			red = red->next;
			j++;
		}
		printf("%s\n", sect->pipe);

		i++;
		printf("\n       ----------------------          \n");
		sect = sect->next;
	}
}



int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char 	*line;

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
		//add_history();
		data->first = parsing(line, env);
		print_pars(data->first);
		//ft_sectclear(data->first);
	}
	free(data);
	return (0);
}