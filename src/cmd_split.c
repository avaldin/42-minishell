/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:19:26 by avaldin           #+#    #+#             */
/*   Updated: 2024/04/15 14:02:45 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	cmd_split(t_section *sect)
{
	int		i;
	int		k;
	char	**new_temp;

	i = 0;
	k = 0;
	new_temp = ft_calloc(cmd_count_word(sect->temp) + 1, sizeof(char *));
	if (!new_temp)
		exit(87); //pas ok
	while (i < sect->tmp_len)
	{
		if (!sect->protection[i])
			new_temp[k] = add_split(sect, )
	}
}