/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:16 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/27 15:37:03 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_pars(t_section *first)
{
	t_section	*sect;
	t_red		*red;
	int 		i = 1;
	int 		j;
	int 		k;

	sect = first;
	while (sect)
	{
		printf("\n           section %d\n\n", i);
		j = 1;
		k = 0;
		red = sect->first_red;
		printf("\ncmd = ");
		while (sect->cmd[k])
		{
			printf("arg %d = %s;    ", k, sect->cmd[k]);
			k++;
		}
		printf("\n");
		while (red)
		{
			printf("\nredirection %d\n\nred name = %s\ndirection = %d\n", j, red->file, red->direction);
			red = red->next;
			j++;
		}
		i++;
		printf("\n       ----------------------          \n");
		sect = sect->next;
	}
}



int	main(void)
{
	t_data	*data;
	char *line;
//	struct sigaction sa;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
//	sa.sa_handler = &
	while (42)
	{
		line = readline("balance ta commande bg >>");
		printf("c = %s = c\n", line);
		data->first = parsing(line);
		print_pars(data->first);
		ft_sectclear(data->first);
	}
	free(data);
	return (0);
}