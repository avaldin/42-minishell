/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:07 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/19 14:06:41 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

enum special_c {NONE, QUOTE, DOUBLE_QUOTE, LEFT_BRACKET, RIGHT_BRACKET, PIPE, DOUBLE_PIPE, DOUBLE_RIGHT_BRACKET, DOUBLE_LEFT_BRACKET};

void	parsing(char *line);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);

#endif
