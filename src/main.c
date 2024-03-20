/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:16 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/20 14:07:58 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

//t_token *init(char **str)
//{
//	t_token *data;
//
//	data = ft_calloc(1, sizeof(t_token));
//}

int	main(int argc, char **argv)
{
	t_section	*data;

	(void)argc;
	//data = init(argv[1]);
	data = parsing(ft_strdup(argv[1]));
	(void)data;
	return (0);
}